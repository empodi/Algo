#include <iostream>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ll;

ll go (ll a, ll b, ll c) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll res = go (a, b / 2, c);
    res = (res * res) % c;
    if (b % 2) res = (res * a) % c;
    return res;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        if (N == 1) cout << 1 << '\n';
        else cout << go (2, N - 2, MOD) << '\n';
    }
    return 0;
}