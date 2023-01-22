#include <cstdlib>
#include <iostream>
using namespace std;

int MAX(int a,int b,int c,int d)
{
    a = a > b ? a:b;
    c = c > d ? c:d;
    return a > c ? a : c;
}

int main()
{
    int N, ans = 0;
    int A[100001] = {0,}, B[100001] = {0,}, C[100001] = {0,};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    B[0] = A[0];
    C[N-1] = A[N-1];
    for (int i = 1; i < N; i++) B[i] = A[i] + B[i - 1];
    for (int i = N - 2; i >= 0; i--) C[i] = A[i] + C[i + 1];
    for (int i = 1; i < N - 1; i++)
    {
        ans = MAX(ans, B[N-2]-A[i]+B[i-1], C[1]-A[i]+C[i+1], B[i]-A[0]+C[i]-A[N-1]);
    }
    printf("%d \n", ans);
    return 0;
}