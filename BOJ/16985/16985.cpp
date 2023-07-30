#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define LEN 5
#define MAX 987654321
#define BLOCK 0
using namespace std;

struct info {
    int x; int y; int z; int cnt;
};

int A[LEN][LEN][LEN], B[LEN][LEN][LEN], org[LEN][LEN][LEN], answer;
bool visited[LEN][LEN][LEN], check[LEN];
const int dirs[6][3] = {{0,-1,0},{0,1,0},{0,0,1},
                        {0,0,-1},{1,0,0},{-1,0,0}};

void init() {
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            for (int k = 0; k < LEN; k++) {
                cin >> org[i][j][k];
            }
        }
    }
    answer = MAX;
}

void rotate(const int & k, int t) {
    if (t == 0) {
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                A[k][i][j] = B[k][i][j];
            }
        }
        return;
    }
    int tmp[LEN][LEN] = {0,};
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            tmp[i][j] = B[k][i][j];
        }
    }
    while (t--) {
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                A[k][i][j] = tmp[LEN - 1 - j][i];
            }
        }
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                tmp[i][j] = A[k][i][j];
            }
        }
    }
}

void BFS() {
    if (A[0][0][0] == BLOCK || A[LEN - 1][LEN - 1][LEN - 1] == BLOCK) return;
    memset(visited, false, sizeof(visited));
    queue<info> q;
    visited[0][0][0] = true;
    q.push({0,0,0, 0});
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (cur.x == LEN - 1 && cur.y == LEN - 1 && cur.z == LEN - 1) {
            answer = min(answer, cur.cnt);
            return;
        }
        for (auto d : dirs) {
            int nx = cur.x + d[0], ny = cur.y + d[1], nz = cur.z + d[2];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= LEN || ny >= LEN || nz >= LEN) continue;
            if (visited[nx][ny][nz] || A[nx][ny][nz] == BLOCK) continue;
            visited[nx][ny][nz] = true;
            q.push({nx, ny, nz, cur.cnt + 1});
        }
    }
}

void makeTurns(vector<int> & t) {
    if (t.size() == LEN) {
        for (int i = 0; i < LEN; i++) {
            rotate(i, t[i]);
        }
        BFS();
        return;
    }
    for (int i = 0; i < 4; i++) {
        t.push_back(i);
        makeTurns(t);
        t.pop_back();
    }
}

void permute() {
    vector<int> v{0, 1, 2 ,3, 4};
    do {
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                for (int k = 0; k < LEN; k++) {
                    B[v[i]][j][k] = org[i][j][k];
                }
            }
        }
        vector<int> t;
        makeTurns(t);
    } while (next_permutation(v.begin(), v.end()));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    vector<int> v;
    permute();
    if (answer != MAX) {
        cout << answer << '\n';
    }
    else {
        cout << "-1 \n";
    }
    return 0;
}
