#include <bits/stdc++.h>
using namespace std;

int height;
int width;
int dp[1001][1001];

void init() {
    
    cin >> height >> width;
    
    for (int i = 0; i < height; i++) {
        
        string str; 
        cin >> str;
        
        for (int j = 0; j < width; j++) {
            dp[i][j] = str[j] - '0';
        }
    }
}

int getMin(int a, int b, int c) {
    
    a = a < b ? a : b;
    
    return a < c ? a : c;
}

int solve() {
    
    int answer = 0;
    
    for (int i = 0; i < height; i++) {
        if (dp[i][0] == 1) 
            answer = 1;
    }
    
    for (int i = 0; i < width; i++) {
        if (dp[0][i] == 1) 
            answer = 1;
    }
    
    for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
            
            if (dp[i][j] == 0) continue;
            
            dp[i][j] = getMin(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            
            answer = answer > dp[i][j] ? answer : dp[i][j];
        }
    }
    
    return answer * answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}