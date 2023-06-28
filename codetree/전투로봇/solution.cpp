#include <iostream>
#include <cstring>
#include <queue>
#define MAX_LEN 20
using namespace std;

struct info {
    int x;
    int y;
    int dist;
};

struct cmp {
    bool operator() (info & a, info & b) {
        if (a.dist == b.dist) {
            if (a.x == b.x) {
                return a.y > b.y;
            }
            return a.x > b.x;
        }
        return a.dist > b.dist;
    }
};

int N, level, kill, sx, sy;
int A[MAX_LEN + 1][MAX_LEN + 1];
bool visited[MAX_LEN + 1][MAX_LEN + 1];
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void init() {
    cin >> N;
    memset(A, 0, sizeof(A));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] == 9) {
                sx = i;
                sy = j;
                A[i][j] = 0;
            }
        }
    }
    level = 2;
    kill = 0;
}

int work() {
    queue<info> q;
    priority_queue<info, vector<info>, cmp> pq;
    q.push(info{sx, sy, 0});
    memset(visited, false, sizeof(visited));
    visited[sx][sy] = true;
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (A[cur.x][cur.y] > 0 && A[cur.x][cur.y] < level) {
            pq.push(cur);
            continue;
        }
        for (auto d : dir) {
            int nx = cur.x + d[0];
            int ny = cur.y + d[1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;
            if (A[nx][ny] > level) continue;
            visited[nx][ny] = true;
            q.push(info{nx, ny, cur.dist + 1});
        }
    }
    if (pq.empty()) return 0;
    sx = pq.top().x;
    sy = pq.top().y;
    A[sx][sy] = 0;
    kill++;
    if (level == kill) {
        level++;
        kill = 0;
    }
    return pq.top().dist;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int answer = 0;
    while (true) {
        int res = work();
        if (!res) break;
        answer += res;
    }
    cout << answer << '\n';
    return 0;
}