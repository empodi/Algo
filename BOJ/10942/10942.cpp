#include <bits/stdc++.h>
using namespace std;

int len;
int numQuestion;
int words[2001];
bool dp[2001][2001] = { false, };

void init() {
    
    cin >> len;
    
    for (int i = 1; i <= len; i++) {
        cin >> words[i];
    }
    
    cin >> numQuestion;
}

void setDP() {
    
    for (int i = 1; i <= len; i++) {
        dp[i][i] = true;
    }
    
    for (int gap = 1; gap <= len - 1; gap++) {
        
        for (int i = 1; i <= len - gap; i++) {
            if (gap == 1) {
                if (words[i] == words[i + gap])
                    dp[i][i + gap] = true;
            }
            else {
                if (words[i] == words[i + gap] && dp[i + 1][i + gap - 1])
                    dp[i][i + gap] = true;
            }
        }
    }
}

void solve() {
    
    setDP();
    
    for (int i = 0; i < numQuestion; i++) {
        int x, y;
        cin >> x >> y;
        
        if (dp[x][y]) cout << "1 \n";
        else cout << "0 \n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    solve();
    
    return 0;
}