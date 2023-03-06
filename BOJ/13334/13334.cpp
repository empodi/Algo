#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int N, K, ret = 0;
vector<pii> v;
priority_queue < int ,vector<int>, greater<> > pq;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v[i].first = max(x, y);
        v[i].second = min(x, y);
    }
    cin >> K;
    sort(v.begin(), v.end());
    for (auto & e : v) {
        pq.push(e.second);
        while (!pq.empty() && pq.top() < e.first - K) pq.pop();
        ret = max(ret, (int) pq.size());
    }
    cout << ret << '\n';
    return 0;
}