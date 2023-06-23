#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define BLOCK 1
#define OK 0
#define EXIT -1
#define RED 2
#define BLUE 3
#define MAX_LEN 10
using namespace std;

struct info {
    int bx;
    int by;
    int rx;
    int ry;
    int cnt;
};

int N, M, sbx, sby, srx ,sry, ox, oy;
int A[MAX_LEN + 1][MAX_LEN + 1];
int draw[MAX_LEN + 1][MAX_LEN + 1];
bool visited[MAX_LEN + 1][MAX_LEN + 1][MAX_LEN + 1][MAX_LEN + 1]; // bx, by, rx, ry

void init() {
    cin >> N >> M;
    memset(A, 0, sizeof(A));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '#') A[i][j] = BLOCK;
            else if (s[j] == 'O') {
                ox = i;
                oy = j;
            }
            else if (s[j] == 'B') {
                sbx = i;
                sby = j;
            }
            else if (s[j] == 'R') {
                srx = i;
                sry = j;
            }
            else A[i][j] = OK;
        }
    }
}

void setDraw(int bx, int by, int rx, int ry) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            draw[i][j] = A[i][j];
        }
    }
    draw[bx][by] = BLUE;
    draw[rx][ry] = RED;
    draw[ox][oy] = EXIT;
}

info UP(int cnt) {
    info ret{0,0,0,0,cnt + 1};
    for (int j = 1; j < M - 1; j++) {
        int i = 1;
        while (i < N - 1) {
            if (draw[i][j] == RED || draw[i][j] == BLUE) {
                int x = i - 1;
                while (x > 0 && draw[x][j] == OK) x--;
                if (draw[x][j] != EXIT) x++;
                if (draw[i][j] == RED) {
                    ret.rx = x;
                    ret.ry = j;
                }
                else {
                    ret.bx = x;
                    ret.by = j;
                }
                if (draw[x][j] != EXIT) {
                    swap(draw[i][j], draw[x][j]);
                }
                else {
                    draw[i][j] = OK;
                }
            }
            i++;
        }
    }
    return ret;
}

info DOWN(int cnt) {
    info ret{0,0,0,0,cnt + 1};
    for (int j = 1; j < M - 1; j++) {
        int i = N - 2;
        while (i > 0) {
            if (draw[i][j] == RED || draw[i][j] == BLUE) {
                int x = i + 1;
                while (x < N - 1 && draw[x][j] == OK) x++;
                if (draw[x][j] != EXIT) x--;
                if (draw[i][j] == RED) {
                    ret.rx = x;
                    ret.ry = j;
                }
                else {
                    ret.bx = x;
                    ret.by = j;
                }
                if (draw[x][j] != EXIT) {
                    swap(draw[i][j], draw[x][j]);
                }
                else {
                    draw[i][j] = OK;
                }
            }
            i--;
        }
    }
    return ret;
}

info RIGHT(int cnt) {
    info ret{0,0,0,0,cnt + 1};
    for (int i = 1; i < N - 1; i++) {
        int j = M - 2;
        while (j > 0) {
            if (draw[i][j] == RED || draw[i][j] == BLUE) {
                int y = j + 1;
                while (y < M - 1 && draw[i][y] == OK) y++;
                if (draw[i][y] != EXIT) y--;
                if (draw[i][j] == RED) {
                    ret.rx = i;
                    ret.ry = y;
                }
                else {
                    ret.bx = i;
                    ret.by = y;
                }
                if (draw[i][y] != EXIT) {
                    swap(draw[i][j], draw[i][y]);
                }
                else {
                    draw[i][j] = OK;
                }
            }
            j--;
        }
    }
    return ret;
}

info LEFT(int cnt) {
    info ret{0,0,0,0,cnt + 1};
    for (int i = 1; i < N - 1; i++) {
        int j = 1;
        while (j < M - 1) {
            if (draw[i][j] == RED || draw[i][j] == BLUE) {
                int y = j - 1;
                while (y > 0 && draw[i][y] == OK) y--;
                if (draw[i][y] != EXIT) y++;
                if (draw[i][j] == RED) {
                    ret.rx = i;
                    ret.ry = y;
                }
                else {
                    ret.bx = i;
                    ret.by = y;
                }
                if (draw[i][y] != EXIT) {
                    swap(draw[i][j], draw[i][y]);
                }
                else {
                    draw[i][j] = OK;
                }
            }
            j++;
        }
    }
    return ret;
}

int solve() {
    queue<info> q;
    q.push({sbx, sby, srx, sry, 0});
    visited[sbx][sby][srx][sry] = true;
    while (!q.empty()) {
        info e = q.front();
//        cout << e.bx << ' ' << e.by << ' ' << e.rx << ' ' << e.ry << ' ' << e.cnt << '\n';
        q.pop();
        if (e.cnt > 10) continue;
        if ((e.rx == ox && e.ry == oy) && !(e.bx == ox && e.by == oy)) return e.cnt;
        if (e.bx == ox && e.by == oy) continue;
        setDraw(e.bx, e.by, e.rx, e.ry);
        info u = UP(e.cnt);
        if (!visited[u.bx][u.by][u.rx][u.ry]) {
            visited[u.bx][u.by][u.rx][u.ry] = true;
            q.push(u);
        }
        setDraw(e.bx, e.by, e.rx, e.ry);
        info d = DOWN(e.cnt);
        if (!visited[d.bx][d.by][d.rx][d.ry]) {
            visited[d.bx][d.by][d.rx][d.ry] = true;
            q.push(d);
        }
        setDraw(e.bx, e.by, e.rx, e.ry);
        info r = RIGHT(e.cnt);
        if (!visited[r.bx][r.by][r.rx][r.ry]) {
            visited[r.bx][r.by][r.rx][r.ry] = true;
            q.push(r);
        }
        setDraw(e.bx, e.by, e.rx, e.ry);
        info l = LEFT(e.cnt);
        if (!visited[l.bx][l.by][l.rx][l.ry]) {
            visited[l.bx][l.by][l.rx][l.ry] = true;
            q.push(l);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    cout << solve() << '\n';
    return 0;
}
