#include <cstdlib>
#include <iostream>
using namespace std;

int N;
int A[5005] = {0,};
int dp[5005][5005] = {0,};

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int gap = 1; gap < N; gap += 2)
    {
        for (int i = 0; i < N - gap; i++)
        {
            if (A[i] == A[i + gap])
            {
                if (gap == 1) dp[i][i + gap] = 1;
                else
                {
                    if (dp[i + 1][i + gap - 1])
                        dp[i][i + gap] = 1;
                }
            }
        }
    }
     
    int cnt = 0, col = N - 1;
    bool flag = false;
    while (1)
    {
        int found = false;
        for (int i = col - 1; i >= 0; i--)
        {
            if (dp[i][col])
            {
                col = i - 1;
                found = true;
                break;
            }
        }
        cnt++;
        if (col < 0)
        {
            flag = true;
            break;
        }
        if (!found) break;
    }
    if (flag) cout << cnt << '\n';
    else cout << -1 << '\n';
    return 0;
}
