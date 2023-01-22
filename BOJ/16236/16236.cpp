#include <bits/stdc++.h>
using namespace std;

#define MAX 987654321
typedef pair<int, int> pii;

int x;
int y;
int len;
int curSize;
int ocean[21][21];
int moving[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
bool visited[21][21];
int answer;

void init() {
    
    cin >> len;
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            
            cin >> ocean[i][j];
            if (ocean[i][j] == 9) {
                x = i;
                y = j;
                ocean[i][j] = 0;
            }
        }
    }
    
    curSize = 2;
    answer = 0;
}

void setFalse() {
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            visited[i][j] = false;
        }
    }
}

bool BFS() {
    
    setFalse();
    
    bool flag = false;
    
    queue<pair<pii, int>> q;
    q.push({{x, y}, 1});
    visited[x][y] = true;
    
    int minDist = MAX;
    int minUp = MAX;
    int minLeft = MAX;
    
    while (!q.empty()) {
        
        int xx = q.front().first.first;
        int yy = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        for (int k = 0; k < 4; k++) {
            int nx = xx + moving[k][0];
            int ny = yy + moving[k][1];
            
            if (nx < 0 || ny < 0 || nx >= len || ny >= len) continue;
            if (ocean[nx][ny] > curSize || visited[nx][ny]) continue;
            
            if (ocean[nx][ny] > 0 && ocean[nx][ny] < curSize) {
                
                flag = true;
                
                if (dist < minDist) {
                    
                    minDist = dist;
                    x = minUp = nx;
                    y = minLeft = ny;
                }
                else if (dist == minDist) {
                    
                    if (nx < minUp) {
                        x = minUp = nx;
                        y = minLeft = ny;
                    }
                    else if (nx == minUp && ny < minLeft) {
                        x = minUp = nx;
                        y = minLeft = ny;
                    }
                }
            }
            
            visited[nx][ny] = true;
            q.push({{nx, ny}, dist + 1});
        }
    }
    
    if (flag) {
        answer += minDist;
        ocean[minUp][minLeft] = 0;
    }
    
    return flag;
}

void solve() {
    
    int cnt = 0;
    
    while (1) {

        if (BFS()) {
            cnt++;
            
            if (cnt == curSize) {
                curSize++;
                cnt = 0;
            }
        }
        else break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    solve();
    
    cout << answer;
    
    return 0;
}