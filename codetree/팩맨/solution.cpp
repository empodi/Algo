#include <iostream>
#include <cstring>
#include <vector>
#define LEN 4
#define MAX_MONSTER 1000000
using namespace std;
typedef pair<int, int> pii;

struct mons {
    int x;
    int y;
    int d;
};

int M, S, sx, sy, maxScore;
vector<int> A[LEN + 1][LEN + 1], tmp[LEN + 1][LEN + 1];
vector<mons> eggs;
int dead[LEN + 1][LEN + 1];
int visited[LEN + 1][LEN + 1];
const int moves[9][2] = {{0,0},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},
                         {1,1},{0,1},{-1,1}};
const int dirs[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

void init() {
    cin >> M >> S;
    cin >> sx >> sy;
    for (int i = 0; i < M; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        A[x][y].push_back(d);
    }
}

void setEggs() {
    eggs.clear();
    for (int i = 1; i <= LEN; i++) {
        for (int j = 1; j <= LEN; j++) {
            for (auto e : A[i][j]) {
                eggs.push_back({i, j, e});
            }
        }
    }
}

bool canMove(int x, int y) {
    if (x < 1 || y < 1 || x > LEN || y > LEN) return false;
    if (dead[x][y]) return false;
    if (x == sx && y == sy) return false;
    return true;
}

void fishMove() {
    for (int i = 1; i <= LEN; i++) {
        for (int j = 1; j <= LEN; j++) {
            tmp[i][j].clear();
        }
    }
    for (int i = 1; i <= LEN; i++) {
        for (int j = 1; j <= LEN; j++) {
            for (auto & e : A[i][j]) {
                int d = e;
                bool flag = false;
                for (int k = 0; k < 8; k++) {
                    int nx = i + moves[d][0];
                    int ny = j + moves[d][1];
                    if (canMove(nx, ny)) {
                        tmp[nx][ny].push_back(d);
                        flag = true;
                        break;
                    }
                    d++;
                    if (d == 9) d = 1;
                }
                if (!flag) {
                    tmp[i][j].push_back(e);
                }
            }
        }
    }
    for (int i = 1; i <= LEN; i++) {
        for (int j = 1; j <= LEN; j++) {
            A[i][j].clear();
            A[i][j] = tmp[i][j];
        }
    }
}

void dfs(int x, int y, int score, vector<pii> & v, vector<pii> & cur) {
    if (x < 1 || y < 1 || x > LEN || y > LEN) return;
    cur.push_back({x, y});
    if (visited[x][y] == 0) {
        score += A[x][y].size();
    }
    visited[x][y]++;
    if (cur.size() == 3) {
        if (score > maxScore) {
            maxScore = score;
            v = cur;
        }
    }
    else {
        for (auto d : dirs) {
            dfs(x + d[0], y + d[1], score, v, cur);
        }
    }
    visited[x][y]--;
    cur.pop_back();
}

void sharkMove() {
    maxScore = -1;
    memset(visited, 0, sizeof(visited));
    vector<pii> v, cur;
    for (auto d : dirs) {
        dfs(sx + d[0], sy + d[1], 0, v, cur);
    }
    for (int i = 1; i <= LEN; i++) {
        for (int j = 1; j <= LEN; j++) {
            if (dead[i][j] > 0) dead[i][j]--;
        }
    }
    sx = v.back().first;
    sy = v.back().second;
    for (auto e : v) {
        if (A[e.first][e.second].size()) {
            dead[e.first][e.second] = 2;
        }
        A[e.first][e.second].clear();
    }
}

void replicate() {
    for (auto & e : eggs) {
        A[e.x][e.y].push_back(e.d);
    }
    eggs.clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    for (int turn = 0; turn < S; turn++) {
        setEggs();
        fishMove();
        sharkMove();
        replicate();
    }
    int answer = 0;
    for (int i = 1; i <= LEN; i++) {
        for (int j = 1; j <= LEN; j++) {
            answer += A[i][j].size();
        }
    }
    cout << answer << '\n';
    return 0;
}