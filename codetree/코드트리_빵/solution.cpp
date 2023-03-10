#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#define LEN 15
#define MAX_M 30
#define CAMP 1
#define NONE -1
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
using namespace std;
typedef pair<int, int> pii;

int N, M;
struct store {
    int x;
    int y;
    int arriveTime; // 사람이 도착하는 시간
};

int origin[LEN + 1][LEN + 1];
store stList [MAX_M + 1];
int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };

void get_input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> origin[i][j];
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> stList[i].x >> stList[i].y;
        stList[i].arriveTime = 0;
    }
}

int getClosestStore(const int & a, const int & b) { // return path length
    int ret = 0;
    bool visited[LEN + 1][LEN + 1];
    memset(visited, false, sizeof(visited));
    queue<pair<pii,int>> q;
    q.push({{a, b},0});
    visited[a][b] = true;
    while (!q.empty()) {
        auto & [tmp, tm] = q.front();
        auto & [x, y] = tmp;
        q.pop();
        if (origin[x][y] == CAMP) {
            ret = tm;
            origin[x][y] = NONE;
            break;
        }
        for (auto & d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx < 1 || ny < 1 || nx > N || ny > N || visited[nx][ny]) continue;
            if (origin[nx][ny] == NONE) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, tm + 1});
        }
    }
    return ret;
}

void setBlocks(const int & curTime) {
    for (int i = 1; i <= M; i++) {
        if (stList[i].arriveTime == 0) continue;
        if (stList[i].arriveTime <= curTime) origin[stList[i].x][stList[i].y] = NONE;
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    for (int t = 1; t <= M; t++) {
        setBlocks(t);
        int pathLen = getClosestStore(stList[t].x, stList[t].y);
        stList[t].arriveTime = t + pathLen;
    }
    int ret = 0;
    for (int i = 1; i <= M; i++) ret = max(ret, stList[i].arriveTime);
    cout << ret << '\n';
    return 0;
}