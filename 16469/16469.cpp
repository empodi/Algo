#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int width;
int height;
int ans;
int cnt;
int maze[201][201];
bool visited[201][201];
int moving[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int a[201][201];    // 넉살
int b[201][201];    // 스윙스
int c[201][201];    // 창모

void init() {
    
    cin >> height >> width;
    
    string str;
    
    for (int i = 1; i <= height; i++) {
        
        cin >> str;
        
        for (int j = 0; j < width; j++) {
            maze[i][j + 1] = str[j] - '0';
        }
    }
}

void BFS(int arr[201][201]) {
    
    int i, j;
    cin >> i >> j;
    
    memset(visited, false, sizeof(visited));
    
    arr[i][j] = 0;
    
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
            
            if (nx < 1 || ny < 1 || nx > height || ny > width) continue;
            if (visited[nx][ny] || maze[nx][ny]) continue;
            
            visited[nx][ny] = true;
            arr[nx][ny] = arr[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int threeMax(int x, int y, int z) {
    
    x = x > y ? x : y;
    
    return x > z ? x : z;
}

void solve() {
    
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    memset(c, -1, sizeof(c));
    
    BFS(a);
    BFS(b);
    BFS(c);
    
    ans = INT_MAX;
    cnt = 0;
    
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            
            if (a[i][j] < 0 || b[i][j] < 0 || c[i][j] < 0) continue;
                
            int val = threeMax(a[i][j], b[i][j], c[i][j]);
                
            if (val < ans) {
                ans = val;
                cnt = 1;
            }
            else if (val == ans) cnt++;
        }
    }
    
    if (cnt == 0) ans = -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    solve();
    
    cout << ans << '\n';
    
    if (cnt > 0) cout << cnt;
    
    return 0;
}