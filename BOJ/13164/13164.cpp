#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long ret = 0;
    int N, K, A[300001];
    vector<int> v;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    v.resize(N - 1);
    for (int i = 1; i < N; i++)
        v[i-1] = A[i] - A[i-1];
    sort(v.begin(),v.end());
    for (int i = 0; i < N - K; i++)
        ret += v[i];
    printf("%lld \n", ret);
    return 0;
}