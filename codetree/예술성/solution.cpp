#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cstring>
#define MAX 30
#define MOD 100001
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int N, cnt;
int origin[MAX + 5][MAX + 5];
int A[MAX + 5][MAX + 5];
int B[MAX + 5][MAX + 5];
bool visited[MAX + 5][MAX + 5];
int area[MAX * MAX + 10];
unordered_map<int,int> um; // { groupNum, realNumber }
unordered_map<int,int> borderPair;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void get_input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> origin[i][j];
        }
    }
}

void flood() {
    cnt = 1;
    memset(visited, false, sizeof(visited));
    memset(area, 0, sizeof(area));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i][j]) continue;
            visited[i][j] = true;
            int target = origin[i][j];
            A[i][j] = cnt;
            um[cnt] = target;
            area[cnt]++;
            queue<pii> q;
            q.push({i, j});
            while (!q.empty()) {
                auto & [x, y] = q.front();
                q.pop();
                for (const auto & d : dir) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 1 || ny < 1 || nx > N || ny > N || visited[nx][ny]) continue;
                    if (origin[nx][ny] == target) {
                        visited[nx][ny] = true;
                        A[nx][ny] = cnt;
                        area[cnt]++;
                        q.push({nx, ny});
                    }
                }
            }
            cnt++;
        }
    }
}

void calBorder() {
    memset(visited, false, sizeof(visited));
    borderPair.clear();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i][j]) continue;
            int cur = A[i][j];
            visited[i][j] = true;
            queue<pii> q;
            q.push({i, j});
            while (!q.empty()) {
                auto & [x, y] = q.front();
                q.pop();
                for (const auto & d : dir) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 1 || ny < 1 || nx > N || ny > N || visited[nx][ny]) continue;
                    if (A[nx][ny] == cur) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                    else { // 경계 계산
                        int hash = min(cur,A[nx][ny]) * MOD + max(cur,A[nx][ny]);
                        borderPair[hash]++;
                    }
                }
            }
        }
    }
}

ll getScore() {
    ll ret = 0;
    for (const auto & [key, value] : borderPair) {
        int x = key / MOD;
        int y = key % MOD;
        ll cur = (ll) area[x] + area[y];
        cur *= (ll) um[x] * um[y] * value;
        ret += cur;
    }
    return ret;
}

void BtoO() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) origin[i][j] = B[i][j];
    }
}

void rotateX() { // 십자 회전
    int x = 1;
    int y = (1 + N) / 2;
    while (x <= y) {
        int diff = abs(x - y);
        int a = x + diff, b = y - diff;
        B[a][b] = origin[x][y]; x = a; y = b;
        a = x + diff; b = y + diff;
        B[a][b] = origin[x][y]; x = a; y = b;
        a = x - diff; b = y + diff;
        B[a][b] = origin[x][y]; x = a; y = b;
        a = x - diff; b = y - diff;
        B[a][b] = origin[x][y]; x = a; y = b;
        x++;
    }
}

void tmpRotate(int len, int a, int b) { //  rotate and copy tmp to B
    int tmp[MAX][MAX], rot[MAX][MAX] = {0,};
    for (int i = 1; i < len; i++) { // copy origin parts to tmp
        for (int j = 1; j < len; j++) {
            tmp[i][j] = origin[i + a][j + b];
        }
    }
    for (int i = 1; i < len; i++) {
        for (int j = 1; j < len; j++) {
            rot[j][len - i] = tmp[i][j];
        }
    }
    for (int i = 1; i < len; i++) {
        for (int j = 1; j < len; j++) {
            B[i + a][j + b] = rot[i][j];
        }
    }
}

void rotatePart() {
    int len = N / 2 + 1;
    tmpRotate(len, 0, 0);
    tmpRotate(len, len, 0);
    tmpRotate(len, 0, len);
    tmpRotate(len, len, len);
}

//void showOrigin() {
//    cout << "Origin -------------------------------------\n";
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= N; j++) {
//            cout << origin[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//}
//
//void showA() {
//    cout << "A -------------------------------------\n";
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= N; j++) {
//            cout << A[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << "Area. ";
//    for (int i = 1; i < cnt; i++) cout << i << ": " << area[i] << "  "; cout << '\n';
//}
//
//void showScore() {
//    cout << "SCORE -------------------------------------\n";
//    for (const auto & [key, value] : borderPair) {
//        int x = key / MOD;
//        int y = key % MOD;
//        cout << "(" << x << ", " << y << ") :" << value << '\n';
//    }
//}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    ll ans = 0;
    for (int k = 0; k < 4; k++) {
        // 점수 계산
        flood();
        calBorder();
        ans += getScore();
        if (k < 3) {
            // 회전
            rotateX();
            rotatePart();
            BtoO();
        }
    }
    cout << ans << '\n';
    return 0;
}