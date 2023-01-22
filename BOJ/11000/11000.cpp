#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int N;
vector<pii> v;

void get_input()
{
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
}

int solve()
{
    int ret = 0;
    priority_queue < pii, vector<pii>, greater<pii> > pq;
    for (auto& e : v)
    {
        while (pq.size() && pq.top().first <= e.first) pq.pop();
        pq.push( {e.second, e.first} );
        ret = max(ret, (int)pq.size());
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    cout << solve() << '\n';
    return 0;
}