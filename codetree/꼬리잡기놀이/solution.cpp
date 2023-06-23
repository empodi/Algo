#include <iostream>
#include <cstring>
#include <vector>
#define MAX_LEN 20
#define MAX_TEAM 5
using namespace std;

struct info {
    int teamId;
    int x;
    int y;
    int seq;
};

struct mapInfo {
    int teamId;
    int num;
    int seq;
};

int N, M, K;
mapInfo A[MAX_LEN + 1][MAX_LEN + 1];
vector<info> teams[MAX_TEAM];
int teamNum[MAX_TEAM];
bool teamDir[MAX_TEAM];
bool check[MAX_LEN + 1][MAX_LEN + 1];

const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x, int y, int teamId, int cnt) {
    if (x < 0 || y < 0 || x >= N || y >= N) return;
    if (check[x][y]) return;
    check[x][y] = true;
    if (A[x][y].num > 1) {
        teams[teamId].push_back({teamId, x, y, A[x][y].num == 4 ? 0 : cnt});
        for (auto d : dir) {
            dfs(x + d[0], y + d[1], teamId, cnt + 1);
        }
    }
}

void init() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j].num;
        }
    }
    memset(teamNum, 0, sizeof(teamNum));
    memset(teamDir, true, sizeof(teamDir));
    memset(check, false, sizeof(check));
}

void setTeams() {
    int tid = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j].num == 1 && !check[i][j]) {
                check[i][j] = true;
                for (auto d : dir) {
                    int nx = i + d[0];
                    int ny = j + d[1];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (A[nx][ny].num == 2) {
                        teams[tid].push_back({tid, i, j, 1});
                        dfs(nx, ny, tid++, 2);
                    }
                }
            }
        }
    }
    for (int i = 0; i < M; i++) {
        int mx = 0;
        for (info e : teams[i]) {
            mx = max(e.seq, mx);
        }
        teamNum[i] = mx;
    }
}

void move() {
    for (int k = 0; k < M; k++) {
        if (teamDir[k]) {
            int tmpSeq = teams[k][0].seq;
            for (int i = 1; i < teams[k].size(); i++) {
                teams[k][i - 1].seq = teams[k][i].seq;
            }
            teams[k].back().seq = tmpSeq;
        }
        else {
            int tmpSeq = teams[k].back().seq;
            for (int i = teams[k].size() - 2; i >= 0; i--) {
                teams[k][i + 1].seq = teams[k][i].seq;
            }
            teams[k][0].seq = tmpSeq;
        }
    }
}

void setMap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j].num = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        for (auto e : teams[i]) {
            A[e.x][e.y].seq = e.seq;
            A[e.x][e.y].teamId = e.teamId;
        }
    }
}

void changeDir(int tid) {
    teamDir[tid] = !teamDir[tid];
    for (info & e : teams[tid]) {
        if (e.seq == 0) continue;
        else e.seq = teamNum[tid] + 1 - e.seq;
    }
}

int getScore(int k) {
    k %= N * 4;
    int sx = 0, sy = 0, dx = 0, dy = 0;
    if (k / N == 0) {
        dx = 0, dy = 1, sy = 0, sx = k % N;
    }
    else if (k / N == 1) {
        dx = -1, dy = 0, sx = N - 1, sy = k % N;
    }
    else if (k / N == 2) {
        dx = 0, dy = -1, sy = N - 1, sx = N - k % N - 1;
    }
    else {
        dx = 1, dy = 0, sx = 0, sy = N - k % N - 1;
    }
    while (sx >= 0 && sy >= 0 && sx < N && sy < N) {
        if (A[sx][sy].seq > 0) {
            changeDir(A[sx][sy].teamId);
            return A[sx][sy].seq * A[sx][sy].seq;
        }
        sx += dx;
        sy += dy;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    setTeams();
    int answer = 0;
    for (int k = 0; k < K; k++) {
        move();
        setMap();
        answer += getScore(k);
    }
    cout << answer << '\n';
    return 0;
}
