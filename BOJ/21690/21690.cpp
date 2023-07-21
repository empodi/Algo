#include <iostream>
#include <cstring>
#include <queue>
#define MAX_LEN 20
#define BLACK -1
#define NONE -2
#define RED 0
using namespace std;

struct info {
    int cnt;
    int redCnt;
    int x;
    int y;
};

struct cmp {
    bool operator() (info & a, info & b) {
        if (a.cnt == b.cnt) {
            if (a.redCnt == b.redCnt) {
                if (a.x == b.x) {
                    return a.y < b.y;
                }
                return a.x < b.x;
            }
            return a.redCnt < b.redCnt;
        }
        return a.cnt < b.cnt;
    }
};

int N, M, sx, sy, redCnt;
int A[MAX_LEN + 1][MAX_LEN + 1];
int tmp[MAX_LEN + 1][MAX_LEN + 1];
bool visited[MAX_LEN + 1][MAX_LEN + 1];
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
priority_queue<info, vector<info>, cmp> pq;

void init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

void setRedFalse() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == RED) visited[i][j] = false;
        }
    }
}

int dfs(int x, int y, const int color) {
    if (x < 0 || y < 0 || x >= N || y >= N || visited[x][y] || A[x][y] == BLACK) return 0;
    if (A[x][y] != color && A[x][y] != RED) return 0;
    visited[x][y] = true;
    if (A[x][y] != RED) {
        if (x == sx) {
            if (y < sy) {
                sy = y;
            }
        }
        else if (x < sx) {
            sx = x;
            sy = y;
        }
    }
    else {
        redCnt++;
    }
    int ret = 1;
    for (auto d : dir) {
        ret += dfs(x + d[0], y + d[1], color);
    }
    return ret;
}

void setBomb() {
    while (!pq.empty()) {
        pq.pop();
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0 && !visited[i][j]) {
                sx = i;
                sy = j;
                redCnt = 0;
                int res = dfs(i, j, A[i][j]);
                setRedFalse();
                if (res >= 2) {
                    pq.push(info{res, redCnt, sx, sy});
                }
            }
        }
    }
}

void expDfs(int x, int y, const int color) {
    if (x < 0 || y < 0 || x >= N || y >= N || A[x][y] == BLACK) return;
    if (A[x][y] == NONE) return;
    if (A[x][y] != color && A[x][y] != RED) return;
    A[x][y] = NONE;
    for (auto d : dir) {
        expDfs(x + d[0], y + d[1], color);
    }
}

int explode() {
    if (pq.empty()) return 0;
    info a = pq.top();
    expDfs(a.x, a.y, A[a.x][a.y]);
    return a.cnt * a.cnt;
}

void down() {
    for (int j = 0; j < N; j++) {
        int i = N - 1;
        while (i >= 0) {
            if (A[i][j] == NONE) {
                int x = i - 1;
                while (x >= 0 && A[x][j] == NONE) x--;
                if (x < 0 || A[x][j] == BLACK) {
                    i = x - 1;
                }
                else {
                    swap(A[i][j], A[x][j]);
                    i--;
                }
            }
            else i--;
        }
    }
}

void rotate() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[N - 1 - j][i] = A[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = tmp[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int answer = 0;
    while (true) {
        setBomb();
        if (pq.empty()) {
            break;
        }
        answer += explode();
        down();
        rotate();
        down();
    }
    cout << answer << '\n';
    return 0;
}