#include <bits/stdc++.h>
using namespace std;

int board[210][101];
int N;
int len;    // 경사로 길이

void init() {
    
    cin >> N >> len;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = N; i < N * 2; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = board[j][i - N];
        }
    }
}

bool check(int idx) {
    
    vector<bool> isSlope(N, false);
    
    for (int i = 1; i < N; i++) {
        
        if (board[idx][i - 1] == board[idx][i])
            continue;
        
        int left = board[idx][i - 1], right = board[idx][i];
        
        if (abs(left - right) > 1) return false;
        
        if (left < right) {
            
            if (i - len < 0) return false;
            
            for (int k = i - len; k <= i - 1; k++) {
                if (board[idx][k] != left || isSlope[k])
                    return false;
            }
            
            if (i - len - 1 >= 0 && board[idx][i - len - 1] > left)
                return false;
            
            for (int k = i - len; k <= i - 1; k++)
                isSlope[k] = true;
        }
        else { // left > right
            if (i + len - 1 >= N) return false;
            
            for (int k = i; k <= i + len - 1; k++) {
                if (board[idx][k] != right || isSlope[k])
                    return false;
            }
            
            if (i + len < N && board[idx][i + len] > right)
                return false;
            
            for (int k = i; k <= i + len - 1; k++)
                isSlope[k] = true;
        }
    }
    
    return true;
}

int solve() {
    
    int answer = 0;
    
    for (int i = 0; i < N * 2; i++) {
        if (check(i)) {
            answer++;
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