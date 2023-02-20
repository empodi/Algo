#include <iostream>
#include <queue>
using namespace std;

struct num {
    int cnt;
    int remain;
};

struct cmp {
    bool operator() (num a, num b) {
        return a.cnt > b.cnt;
    }
};

int A[10];
priority_queue <num, vector<num>, cmp> pq;

int solve() {
    int N, K, ret = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> K;
    pq.push({0, K});
    while (!pq.empty()) {
        int c = pq.top().cnt;
        int n = pq.top().remain;
        pq.pop();
        if (n == 0) {
            ret = c;
            break;
        }
        pq.push({c + n, 0});
        for (int i = 0; i < N; i++) pq.push({c + n % A[i], n / A[i]});
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        while (!pq.empty()) pq.pop();
        int ans = solve();
        cout << '#' << i << ' ' << ans  << '\n';
    }
    return 0;
}