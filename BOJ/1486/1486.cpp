#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int N, M, T, D;
int A[30][30]; // 가는 시간
int B[30][30]; // 돌아오는 시간
int height[30][30] = {0,};
int mv[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int getHeight(const char& c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

void init() {
    cin >> N >> M >> T >> D;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < M; j++) height[i][j] = getHeight(s[j]);
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) A[i][j] = B[i][j] = MAX;
}

int goTime(int src, int dest) {
    if (dest <= src) return 1;
    else return (dest - src) * (dest - src);
}

void going(int x, int y, int prevH, int tm) {
    if (x < 0 || y < 0 || x >= N || y >= M) return;
    if (abs(prevH - height[x][y]) > T) return;
    if (x || y) tm += goTime(prevH, height[x][y]);
    if (tm >= A[x][y]) return;
    A[x][y] = tm;
    for (auto & e : mv) going(x + e[0], y + e[1], height[x][y], tm);
}

int retTime(int src, int dest) {
    if (dest < src) return (dest - src) * (dest - src);
    else return 1;
}

void returning(int x, int y, int prevH, int tm) {
    if (x < 0 || y < 0 || x >= N || y >= M) return;
    if (abs(prevH - height[x][y]) > T) return;
    if (x || y) tm += retTime(prevH, height[x][y]);
    if (tm >= B[x][y]) return;
    B[x][y] = tm;
    for (auto & e : mv) returning(x + e[0], y + e[1], height[x][y], tm);
}

int maxHeight() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == MAX || B[i][j] == MAX) continue;
            if ((long long)A[i][j] + (long long)B[i][j] <= (long long)D)
                ret = max(ret, height[i][j]);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    init();
    going(0,0,height[0][0],0);
    returning(0,0,height[0][0],0);
    cout << maxHeight() << '\n';
    return 0;
}