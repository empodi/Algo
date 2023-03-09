#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define MAX 20
#define MAX_PLAYER 30
using namespace std;

struct player {
    void set() {
        x = y = direction = power = point = gun = 0;
    }
    int x;
    int y;
    int direction;
    int power;
    int gun;
    int point;
};

int N, M, K;
priority_queue<int> guns[MAX + 1][MAX + 1];
player plist[MAX_PLAYER + 1];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

void get_input() {
    for (int i = 0; i <= MAX_PLAYER; i++) plist[i].set();
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            if (x) guns[i][j].push(x);
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> plist[i].x >> plist[i].y >> plist[i].direction >> plist[i].power;
    }
}

int check(int x, int y) { // (x, y)에 플레이어가 있으면 플레이어 번호, 없으면 -1
    for (int i = 1; i <= M; i++) {
        if (plist[i].x == x && plist[i].y == y) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    while (K--) {
        for (int i = 1; i <= M; i++) {
            int curX = plist[i].x, curY = plist[i].y;
            int curD = plist[i].direction;
            int nx = curX + dir[curD][0], ny = curY + dir[curD][1];
            if (nx < 1 || ny < 1 || nx > N || ny > N) { // 플레이어 진행 방향 바꾸는 경우
                plist[i].direction = (plist[i].direction + 2) % 4;
                curD = plist[i].direction;
                nx = curX + dir[curD][0];
                ny = curY + dir[curD][1];
            }
//            cout << "-------------------------------------------------------------\n";
//            cout << i << "번 플레이어 " << nx << ", " << ny << "로 이동 \n";
            int opt = check(nx, ny);    // 움직일 수 있는지 체크
            plist[i].x = nx;    // 플레이어의 새로운 위치 설정
            plist[i].y = ny;
            if (opt > 0) {  // 싸움
                int win, lose;
                int other = opt;
                if (plist[i].power + plist[i].gun == plist[other].power + plist[other].gun) {
                    if (plist[i].power > plist[other].power) {
                        win = i;
                        lose = other;
                    }
                    else {
                        win = other;
                        lose = i;
                    }
                }
                else if (plist[i].power + plist[i].gun > plist[other].power + plist[other].gun) {
                    win = i;
                    lose = other;
                }
                else {
                    win = other;
                    lose = i;
                }
//                cout << "승리: " << win << " ...  (" << plist[win].x << ", " << plist[win].y << ") \n";
//                cout << "패배: " << lose << " ...  (" << plist[lose].x << ", " << plist[lose].y << ") \n";
                plist[win].point += abs(plist[win].power + plist[win].gun - plist[lose].power - plist[lose].gun);

                if (plist[lose].gun > 0) { // 진 사람 총 내려놓기
                    guns[nx][ny].push(plist[lose].gun);
                    plist[lose].gun = 0;
                }
                for (int k = 0; k < 4; k++) { // 진 사람 이동
                    int mx = nx + dir[plist[lose].direction][0];
                    int my = ny + dir[plist[lose].direction][1];
                    if (mx < 1 || my < 1 || mx > N || my > N || check(mx, my) > 0) {
                        plist[lose].direction = (plist[lose].direction + 1) % 4;
                        continue;
                    }
                    if (!guns[mx][my].empty()) {
                        plist[lose].gun = guns[mx][my].top();
                        guns[mx][my].pop();
                    }
                    plist[lose].x = mx;
                    plist[lose].y = my;
                    break;
                }
                if (!guns[plist[win].x][plist[win].y].empty()) { // 이긴 사람의 총 설정
                    int newGun = guns[plist[win].x][plist[win].y].top();
                    if (newGun > plist[win].gun) {
                        if (plist[win].gun > 0) guns[plist[win].x][plist[win].y].push(plist[win].gun);
                        plist[win].gun = newGun;
                        guns[plist[win].x][plist[win].y].pop();
                    }
                }
            }
            else {  // 이동
                if (!guns[nx][ny].empty()) { // 새로 이동한 곳의 총 설정
                    int newGun = guns[nx][ny].top();
                    if (plist[i].gun == 0) {
                        plist[i].gun = newGun;
                        guns[nx][ny].pop();
                    }
                    else if (newGun > plist[i].gun) {
                        guns[nx][ny].push(plist[i].gun);
                        plist[i].gun = newGun;
                        guns[nx][ny].pop();
                    }
                }
            }
        }
//        for (int j = 1; j <= M; j++) {
//            cout << j << ": (" << plist[j].x << ", " << plist[j].y << ") \n";
//        }
    }
    for (int i = 1; i <= M; i++) cout << plist[i].point << ' ';
    return 0;
}