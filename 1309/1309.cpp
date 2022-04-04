#include <bits/stdc++.h>
using namespace std;

#define DIV 9901

int len;
int dp[100001][4];

void init() {
    
    memset(dp, 0, sizeof(dp));
    cin >> len;
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    for (int i = 1; i <= len; i++) {
        
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % DIV;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % DIV;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % DIV;
        
        dp[i][3] = dp[i][0] + dp[i][1] + dp[i][2];
        dp[i][3] %= DIV;
    }
    
    cout << dp[len][3] << '\n';
    
    return 0;
}