#include <iostream>
using namespace std;
inline int max(int a,int b){return a > b? a:b;}

int main()
{
    int N, K, A[200001] = {0,}, cnt[100001] = {0,};
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    int s = 0, e = 0, ret = 0;
    while (e < N)
    {
        while (s < e && cnt[A[e]] == K)
        {
            cnt[A[s]]--;
            s++;
        }
        ret = max(ret,e-s+1);
        cnt[A[e]]++;
        e++;
    }
    printf("%d \n", ret);
    return 0;
}