#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void solve() {
    int N, mid, cnt = 0;
    cin >> N;
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    cout << (N / 2 + 1) << '\n';
    for (int i = 1; i <= N; i += 2) {
        if (i == 1) {
            cin >> mid;
        }
        else {
            int a, b;
            cin >> a >> b;
            small.push(min(a,b));
            big.push(max(a,b));

            int x = small.top(), y = big.top();
            small.pop();
            big.pop();
            vector<int> v{x, y, mid};
            sort(v.begin(), v.end());
            small.push(v[0]);
            big.push(v[2]);
            mid = v[1];
        }
        cout << mid << ' ';
        cnt++;
        if (cnt % 10 == 0) cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}