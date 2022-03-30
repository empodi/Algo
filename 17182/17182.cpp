#include <bits/stdc++.h>
using namespace std;

int len;
int start;
int graph[11][11];
bool visited[11];

int ans;

void init() {
    
    cin >> len >> start;
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cin >> graph[i][j];
        }
    }
    
    memset(visited, false, sizeof(visited));
    ans = INT_MAX;
}

void setFloydWarshall() {
    
    for (int k = 0; k < len; k++) {
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                
                if (i == j) continue;
                
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void solve(int prev, int cnt, int sum) {

    if (cnt == len) {
        ans = ans < sum ? ans : sum;
        return;
    }
    
    for (int i = 0; i < len; i++) {
        
        if (visited[i]) continue;
        
        visited[i] = true;
        solve(i, cnt + 1, sum + graph[prev][i]);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    setFloydWarshall();
    
    visited[start] = true;
    solve(start, 1, 0);
    
    cout << ans;
    
    return 0;
}