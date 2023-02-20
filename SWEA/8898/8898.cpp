#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <climits>
#define MAX 500000
using namespace std;

int N, M, fixedX, fixedY;
long long minDiff;
int A[MAX + 1], B[MAX + 1];

int lowBound(const int & target) {
    int lo = 0, hi = M - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (B[mid] >= target) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int solve() {
    int globalCnt = 0;
    for (int i = 0; i < N; i++) {
        int target = A[i];
        int idx = lower_bound(B, B + M, target) - B;
        int diff = 0, same = 0;
        if (idx >= M) {
            diff = abs(B[M - 1] - target);
        }
        else if (idx == 0) {
            diff = abs(B[0] - target);
        }
        else {
            diff = min(abs(B[idx] - target), abs(B[idx - 1] - target));
            if (abs(B[idx] - target) == abs(B[idx - 1] - target)) same = 1;
        }

        if (diff == minDiff) {
            if (same) globalCnt += 2;
            else globalCnt++;
        }
        else if (diff < minDiff) {
            minDiff = diff;
            if (same) globalCnt = 2;
            else globalCnt = 1;
        }
    }
    return globalCnt;
}

void init() {
    minDiff = INT_MAX;
    cin >> N >> M;
    cin >> fixedX >> fixedY;
    int x;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(B, B + M);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        init();
        int res = solve();
        cout << '#' << i << ' ' << minDiff + abs(fixedX - fixedY) << ' ' << res << '\n';
    }
    return 0;
}