#include <bits/stdc++.h>
using namespace std;

int height;
int width;
int tLen;
int answer;

char table[6][6];
bool visited[6][6];
int moving[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

void init() {
    
    cin >> height >> width >> tLen;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> table[i][j];
            visited[i][j] = false;
        }
    }
    
    answer = 0;
}

void DFS(int i, int j, int curLen) {
    
    if (visited[i][j] || table[i][j] == 'T') return;
    
    if (curLen == tLen && i == 0 && j == width - 1) {
        answer++;
        return;
    }
    
    visited[i][j] = true;
    
    for (int k = 0; k < 4; k++) {
        int x = i + moving[k][0];
        int y = j + moving[k][1];
        
        if (x < 0 || y < 0 || x >= height || y >= width) continue;
        if (table[x][y] == 'T') continue;
        
        DFS(x, y, curLen + 1);
    }
    
    visited[i][j] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    DFS(height - 1, 0, 1);
    
    cout << answer;
    
    return 0;
}