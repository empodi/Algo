#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int height;
int width;
int ocean[310][310];
int tmp[310][310];
bool visited[310][310];
int moving[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void init() {
    
    cin >> height >> width;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> ocean[i][j];
        }
    }
}

void setArrays() {
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            visited[i][j] = false;
            tmp[i][j] = 0;
        }
    }
}

void setOcean() {
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ocean[i][j] -= tmp[i][j];
            if (ocean[i][j] < 0)
                ocean[i][j] = 0;
        }
    }
}

int getIceberg() {
    
    setArrays();
    
    int ret = 0;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (ocean[i][j] == 0 || visited[i][j]) continue;
            
            ret++;
            
            queue<pii> q;
            q.push({i, j});
            visited[i][j] = true;
            
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int nx = x + moving[k][0];
                    int ny = y + moving[k][1];
                    
                    if (nx < 0 || nx < 0 || nx >= height || ny >= width) continue;
                    if (visited[nx][ny] || ocean[nx][ny] == 0) continue;
                    
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            
        }
    }
    
    return ret;
}

int solve() {
    
    int time = 0;
    
    while(1) {
        
        setArrays();
        bool iceExists = false;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (visited[i][j] || ocean[i][j] != 0) continue;
                
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = true;
        
                while (!q.empty()) {
            
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
            
                    for (int k = 0; k < 4; k++) {
                        int nx = x + moving[k][0];
                        int ny = y + moving[k][1];
                
                        if (nx < 0 || ny < 0 || nx >= height || ny >= width) continue;
                        if (visited[nx][ny]) continue;
                
                        if (ocean[nx][ny] == 0) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                        else {
                            tmp[nx][ny]++;
                            iceExists = true;
                        }
                    }
                }
                
            }
        }
        
        setOcean();
        
        if (iceExists) time++;
        
        int numOfIceberg = getIceberg();
        
        if (numOfIceberg == 0) return 0;
        else if (numOfIceberg >= 2) return time;
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}