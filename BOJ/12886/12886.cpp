#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1500
typedef pair<int,int> pii;

int N, S;
int visited[MAX + 10][MAX + 10] = {0,};
int A[3], tmp[3];

int solve() {
    cin >> A[0] >> A[1] >> A[2];
    S = A[0] + A[1] + A[2];
    sort(A, A + 3);
    queue<pii> q;
    q.push({A[0], A[1]});
    visited[A[0]][A[1]] = 1;
    while (!q.empty()) {
        auto & [x, y] = q.front();
        q.pop();
        int z = S - x - y;
        if (x == y && y == z) return 1;
        A[0] = x;
        A[1] = y;
        A[2] = z;
        sort(A, A + 3);
        for (int i = 0; i < 2; i++) {
            for (int j = i + 1; j < 3; j++) {
                tmp[0] = A[i] * 2;
                tmp[1] = A[j] - A[i];
                tmp[2] = A[3 - i - j];
                sort(tmp, tmp + 3);
                if (visited[tmp[0]][tmp[1]]) continue;
                else {
                    visited[tmp[0]][tmp[1]] = 1;
                    q.push({tmp[0], tmp[1]});
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout << solve() << '\n';
    return 0;
}