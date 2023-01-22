#include <bits/stdc++.h>
using namespace std;

enum Direction {
    NORTH, EAST, SOUTH, WEST
};

int height;
int width;
int r;
int c;
int startDirection;
int answer;
int board[51][51];
bool visited[51][51];
int moving[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

void init() {
    
    cin >> height >> width;
    cin >> r >> c >> startDirection;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> board[i][j];
            visited[i][j] = false;
        }
    }
    answer = 0;
}

int getNextDirection(int curDirection) {
    
    if (curDirection == NORTH) return WEST;
    else if (curDirection == WEST) return SOUTH;
    else if (curDirection == SOUTH) return EAST;
    else return NORTH;
}

int getBackDirection(int curDirection) {
    
    if (curDirection == NORTH) return SOUTH;
    else if (curDirection == WEST) return EAST;
    else if (curDirection == SOUTH) return NORTH;
    else return WEST;
}

void DFS(int x, int y, int curDir) {
    
    if (board[x][y] == 0 && !visited[x][y]) answer++;
    visited[x][y] = true;
    
    int nextDir = curDir;
    
    for (int i = 0; i < 4; i++) {
        nextDir = getNextDirection(nextDir);
        
        int nx = x + moving[nextDir][0];
        int ny = y + moving[nextDir][1];
        
        if (nx < 0 || ny < 0 || nx >= height || ny >= width) continue;
        if (visited[nx][ny] || board[nx][ny] == 1) continue;
        
        DFS(nx, ny, nextDir);
        return;
    }
    
    int backDir = getBackDirection(curDir);
    int bx = x + moving[backDir][0];
    int by = y + moving[backDir][1];
    
    if (board[bx][by] == 1) return;
    
    DFS(bx, by, curDir);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    DFS(r, c, startDirection);
    
    cout << answer;
    
    return 0;
}