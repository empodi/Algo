#include <bits/stdc++.h>
using namespace std;

int nodeNum;
int pairNum;
int floyd[1001][1001];

void init() {
    
    cin >> nodeNum >> pairNum;
    
    for (int i = 1; i <= nodeNum; i++) {
        for (int j = 1; j <= nodeNum; j++) {
            
            if (i == j) floyd[i][j] = 0;
            else floyd[i][j] = INT_MAX;
        }
    }
    
    for (int i = 0; i < nodeNum - 1; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        
        floyd[x][y] = floyd[y][x] = c;
    }
}

void setFloydWarshall() {
    
    for (int k = 1; k <= nodeNum; k++) {
        for (int i = 1; i <= nodeNum; i++) {
            for (int j = 1; j <= nodeNum; j++) {
                
                if (floyd[i][k] == INT_MAX || floyd[k][j] == INT_MAX) {
                    continue;
                }
                
                if (floyd[i][k] + floyd[k][j] < floyd[i][j]) {
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }
}

void solve() {
    
    for (int i = 0; i < pairNum; i++) {
        
        int x, y;
        cin >> x >> y;
        
        cout << floyd[x][y] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    setFloydWarshall();
    
    solve();
    
    return 0;
}