#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define LEN 100000
typedef long long ll;

int N;
struct info {
    int pos;
    int people;
    ll prefixSum;
};

info A[LEN + 1];

bool cmp (info a, info b) {
    return a.pos < b.pos;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i].pos >> A[i].people;
    sort(A, A + N, cmp);
//    for (int i = 0; i < N; i++) cout << A[i].pos << ' ' << A[i].people << '\n';
    A[0].prefixSum = A[0].people;
    for (int i = 1; i < N; i++) A[i].prefixSum = A[i].people + A[i - 1].prefixSum;
    int lo = 0, hi = N - 1, ret = INT_MAX;
    while (lo <= hi) {
        int mid = (lo + hi) / 2 ;
        ll left = A[mid].prefixSum;
        ll right = A[N - 1].prefixSum - A[mid].prefixSum;
        if (left >= right) {
            ret = min(ret, A[mid].pos);
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}