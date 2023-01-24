#include <cstdlib>
#include <iostream>
#define MOD 987654321
using namespace std;
typedef long long ll;

ll solve(const int& N)
{
    int P[1000001];
    ll answer = 1;
    
    for (int i = 0; i <= N; i++) P[i] = i;
    for (int i = 2; i <= N; i++)
    {
        if (P[i] == 0) continue;
        for (int j = i * 2; j <= N; j += i)
            P[j] = 0;
    }
    for (int i = 2; i <= N; i++)
    {
        if (P[i])
        {
            ll x = (ll)i;
            while (x < N) x *= (ll)i;
            if (x > N) x /= i;;
            answer *= x;
            answer %= MOD;
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int N;
    scanf("%d", &N);
    printf("%lld \n", solve(N));
    
    return 0;
}
