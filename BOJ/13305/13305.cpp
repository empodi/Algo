#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int N, dist[100005] = {0,}, price[100005] = {0,};
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) scanf("%d", &dist[i]);
    for (int i = 0; i < N; i++) scanf("%d", &price[i]);
    
    int minPrice = price[0];
    long long ans = (long long)price[0] * dist[0];
    for (int i = 1; i < N - 1; i++)
    {
        minPrice = price[i] < minPrice ? price[i] : minPrice;
        ans += (long long)dist[i] * minPrice;
    }
    printf("%lld \n", ans);
    return 0;
}