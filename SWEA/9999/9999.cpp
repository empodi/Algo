#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;

struct info {
    int begin;
    int end;
    ll prefixSum;
};

int len, N;
info A[MAX + 1];

int findLastEnd(const int & target) {
    int lo = 0, hi = N - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (A[mid].end >= target) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

ll solve() {
    ll ret = 0;
    for (int i = 0; i < N; i++) {

        int adStart = A[i].begin, adEnd = A[i].begin + len;
        int lastIdx = findLastEnd(adEnd);
        if (lastIdx < 0) continue;

        ll total = A[lastIdx].prefixSum - A[i].prefixSum + A[i].end - A[i].begin;

        if (adEnd < A[lastIdx].end && adEnd > A[lastIdx].begin) total -= A[lastIdx].end - adEnd;
        else if (adEnd <= A[lastIdx].begin) total -= A[lastIdx].end - A[lastIdx].begin;

        ret = ret > total ? ret : total;
    }
    return ret;
}

void init() {
    cin >> len;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        A[i].begin = x;
        A[i].end = y;
        if (i == 0) A[i].prefixSum = y - x;
        else A[i].prefixSum = A[i - 1].prefixSum + (y - x);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        init();
        ll res = solve();
        cout << '#' << i << ' ' << res << '\n';
    }
    return 0;
}