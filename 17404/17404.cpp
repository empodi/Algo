#include <bits/stdc++.h>
using namespace std;

#define MAX 987654321

int len;
int cost[1001][3];
int dp[1001][3];

void init() {
    
    cin >> len;
    
    for (int i = 1; i <= len; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
}

int solve() {
    
    int answer = MAX;
    
    for (int color = 0; color < 3; color++) {
        
        for (int i = 0; i < 3; i++) {
            dp[1][i] = (i == color) ? cost[1][i] : MAX;
        }
        
        for (int i = 2; i <= len; i++) {
            
            for (int j = 0; j < 3; j++) {
                dp[i][j] = cost[i][j];
            }
            
            dp[i][0] += dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2];
            dp[i][1] += dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2];
            dp[i][2] += dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1];
        }
        
        for (int i = 0; i < 3; i++) {
            
            if (i != color) {
                answer = dp[len][i] < answer ? dp[len][i] : answer;
            }
        }
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}