#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int len;

void init() {
    
    memset(dp, 0, sizeof(dp));
    scanf("%d", &len);
}

int solve() {
    
    dp[0] = dp[1] = 1;
    
    for (int i = 2; i <= len; i++) {
        
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        dp[i] %= 10007;
    }
    
    return dp[len];
}

int main() {

    init();
    
    cout << solve();
    
    return 0;
}