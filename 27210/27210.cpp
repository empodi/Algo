#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int pos = 0, neg = 0, N;
    int A[100001] = {0,};
    int B[100001] = {0,};
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x == 2) x = -1;
        if (i == 0) A[0] = B[0] = pos = neg = x;
        else
        {
            A[i] = max(A[i - 1] + x, x);
            B[i] = min(B[i - 1] + x, x);
            pos = max(pos, A[i]);
            neg = min(neg, B[i]);
        }
    }
    cout << max( abs(pos), abs(neg) ) << '\n';
    return 0;
}
