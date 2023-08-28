#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define LEN 50
#define BLOCK 1
#define VIRUS 2
#define DONE 3
#define MAX 987654321
using namespace std;
typedef pair<int,int> pii;

int N, M, answer;
int A[LEN + 1][LEN + 1], B[LEN + 1][LEN + 1];
bool visited[LEN + 1][LEN + 1];
vector<int> v;
vector<pii> virus;
const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int blanks = 0;

void init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] == VIRUS) virus.push_back({i, j});
            if (A[i][j] == 0) blanks++;
        }
    }
    answer = MAX;
    memset(visited, false, sizeof(visited));
    v.clear();
}

void AtoB() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = A[i][j];
        }
    }
}

int bfs() {
    int cnt = 0, blankCnt = 0;
    queue<pii> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] == 0) blankCnt++;
        }
    }
    for (auto & e: v) {
        q.push({virus[e].first, virus[e].second});
        B[virus[e].first][virus[e].second] = DONE;
    }
    while (!q.empty()) {
        queue<pii> temp_q;
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            for (auto &d: dirs) {
                int nx = cur.first + d[0];
                int ny = cur.second + d[1];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (B[nx][ny] == DONE || B[nx][ny] == BLOCK) continue;
                if (B[nx][ny] == 0) blankCnt--;
                B[nx][ny] = DONE;
                temp_q.push({nx, ny});
            }
        }
        q = temp_q;
        if (!q.empty()) {
            cnt++;
        }
        if (blankCnt == 0) break;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] == 0) return MAX;
        }
    }
    return cnt;
}

void go(int idx) {
    if (v.size() == M) {
        AtoB();
        answer = min(answer, bfs());
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        v.push_back(i);
        go(i + 1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    if (blanks) {
        go(0);
        cout << (answer == MAX ? -1 : answer) << '\n';
    }
    else {
        cout << 0 << '\n';
    }
    return 0;
}
