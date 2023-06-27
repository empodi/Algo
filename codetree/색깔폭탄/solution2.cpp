
// Without Priority Queue
#include <iostream>
#include <cstring>
#define MAX_LEN 20
#define BLACK -1
#define NONE -2
#define RED 0
using namespace std;

struct Info {
    int cnt;
    int redCnt;
    int x;
    int y;
};

Info info;
int N, M, sx, sy, redCnt;
int A[MAX_LEN + 1][MAX_LEN + 1];
int tmp[MAX_LEN + 1][MAX_LEN + 1];
bool visited[MAX_LEN + 1][MAX_LEN + 1];
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

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
        else if (x > sx) {
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

void setInfo(int cnt, int rc, int x, int y) {
    info.cnt = cnt;
    info.redCnt = rc;
    info.x = x;
    info.y = y;
}

int setBomb() {
    int ret = 0;
    redCnt = 0;
    setInfo(-1, -1, -1, -1);
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > RED && !visited[i][j]) {
                sx = i;
                sy = j;
                redCnt = 0;
                int res = dfs(i, j, A[i][j]);
                setRedFalse();
                if (res >= 2) {
                    ret++;
                    if (res > info.cnt){
                        setInfo(res, redCnt, sx, sy);
                    }
                    else if (res == info.cnt) {
                        if (redCnt == info.redCnt) {
                            if (sx == info.x) {
                                if (sy < info.y) setInfo(res, redCnt, sx, sy);
                            }
                            else if (sx > info.x) setInfo(res, redCnt, sx, sy);
                        }
                        else if (redCnt < info.redCnt) setInfo(res, redCnt, sx, sy);
                    }
                }
            }
        }
    }
    return ret;
}

void expDfs(int x, int y, const int color) {
    if (x < 0 || y < 0 || x >= N || y >= N) return;
    if (A[x][y] == NONE || A[x][y] == BLACK) return;
    if (A[x][y] == color || A[x][y] == RED) {
        A[x][y] = NONE;
        for (auto d: dir) {
            expDfs(x + d[0], y + d[1], color);
        }
    }
}

int explode() {
    if (info.cnt < 0) return 0;
    expDfs(info.x, info.y, A[info.x][info.y]);
    return info.cnt * info.cnt;
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
        int res = setBomb();
        if (res == 0) break;
        answer += explode();
        down();
        rotate();
        down();
    }
    cout << answer << '\n';
    return 0;
}