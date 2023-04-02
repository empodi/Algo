#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define LEN 100
#define MAX 987654321
using namespace std;
typedef pair<int,int> pii;

int N, ans;
int A[LEN + 1][LEN + 1];
bool visited[LEN + 1][LEN + 1];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    ans = MAX;
}

void go(int x, int y) {
    if (A[x][y] == 0) return;
    A[x][y] = 0;
    for (auto d : dir) {
        int nx = x + d[0];
        int ny = y + d[1];
        if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
        go(nx, ny);
    }
}

void flood() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i][j]) {
                memset(visited, false, sizeof(visited));
                queue<pii> q, edge_q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [x,  y] = q.front();
                    q.pop();
                    for (auto & d : dir) {
                        int nx = x + d[0];
                        int ny = y + d[1];
                        if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                        if (visited[nx][ny]) continue;
                        if (A[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                        else {
                            edge_q.push({x, y});
                        }
                    }
                }
                int cnt = 0;
                bool flag = true;
//                cout << "edgeq size: " << edge_q.size() << '\n';
                while (!edge_q.empty() && flag) {
                    queue<pii> temp_q;
                    while (!edge_q.empty() && flag) {
                        auto [x, y] = edge_q.front();
//                        if (cnt == 1) cout << x << ", " << y << '\n';
                        edge_q.pop();
                        for (auto & d : dir) {
                            int nx = x + d[0];
                            int ny = y + d[1];
                            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                            if (visited[nx][ny]) continue;
                            if (A[nx][ny]) {
                                ans = min(cnt, ans);
                                flag = false;
                                break;
                            }
                            visited[nx][ny] = true;
                            temp_q.push({nx, ny});
                        }
                    }
                    swap(temp_q, edge_q);
                    cnt++;
                }
                go(i, j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    flood();
    cout << ans << '\n';
    return 0;
}
