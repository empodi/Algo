#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;

int N, P;
int A[MAX + 1];
int B[MAX + 1];

void init() {
    cin >> N >> P;
    for (int i = 0; i < N; i++) cin >> A[i];
    B[0] = 0;
    for (int i = 1; i < N; i++) B[i] = B[i - 1] + A[i] - A[i - 1] - 1;
}

int solve() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int lo = i, hi = N - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int res = B[mid] - B[i];
            if (res > P) hi = mid - 1;
            else {
                ret = max(ret, A[mid] - A[i] + P - res + 1);
                lo = mid + 1;
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        init();
        int ans = solve();
        cout << '#' << i << ' ' << ans << '\n';
    }
    return 0;
}