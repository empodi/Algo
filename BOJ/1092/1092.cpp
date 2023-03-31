#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50
using namespace std;

int N, M;
int A[MAX + 10];
vector<int> v;

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    v.resize(M);
    for (int i = 0; i < M; i++) cin >> v[i];
    sort(A, A + N);
    sort(v.begin(), v.end());
}

int solve() {
    if (A[N - 1] < v.back()) return -1;
    int ret = 1;
    while (true) {
        for (int i = 0; i < N && !v.empty(); i++) {
            int idx = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            if (idx < v.size() && v[idx] == A[i]) v.erase(v.begin() + idx);
            else if (idx > 0 && v[idx - 1] <= A[i]) v.erase(v.begin() + idx - 1);
        }
//        for (auto & e : v) cout << e << ' '; cout << '\n';
        if (v.empty()) break;
        ret++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    cout << solve() << '\n';
    return 0;
}
