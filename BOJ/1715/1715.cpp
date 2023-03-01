#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef unsigned long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    ll ret = 0;
    priority_queue< ll, vector<ll>, greater<> > pq;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ret += a + b;
        pq.push(a + b);
    }
    cout << ret << '\n';
    return 0;
}