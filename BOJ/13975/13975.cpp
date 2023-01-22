#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

ll solve()
{
    int N;
    cin >> N;
    ll ret = 0;
    priority_queue < ll ,vector<ll>, greater<ll> > pq;
    while (N--)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() > 1)
    {
        ll x = pq.top(); 
        pq.pop();
        ll y = pq.top();
        pq.pop();
        ret += (x + y);
        pq.push(x + y);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cout << solve() << '\n';
    }
    return 0;
}