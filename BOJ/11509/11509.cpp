#include <iostream>
#define MAX int(1e6)
using namespace std;

int main()
{
    int N, check[MAX + 10] = {0,}, ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        if (x < MAX && check[x + 1]) check[x + 1]--;
        check[x]++;
    }
    for (int i = 0; i <= MAX; i++) ans += check[i];
    printf("%d \n", ans);
    return 0;
}