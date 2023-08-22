#include <cstdlib>
#include <iostream>
#include <queue>
#define MAX 987654321
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;

int height, width, sx, sy, sd, ex, ey, ed;
int map[101][101], visited[101][101][5];
const int dir[5][2] = { {0,0/*not used*/}, {0,1},{0,-1},{1,0},{-1,0} };

const int EAST = 1;
const int WEST = 2;
const int SOUTH = 3;
const int NORTH = 4;

void init() {
    cin >> height >> width;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            cin >> map[i][j];
        }
    }
    cin >> sx >> sy >> sd;
    cin >> ex >> ey >> ed;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) { 
            for (int k = 1; k < 5; k++) {
                visited[i][j][k] = MAX;
            }
        }
    }
}

int calDirCost(const int& x, const int& y) {
    if (x == EAST && y == WEST) return 2;
    if (x == WEST && y == EAST) return 2;
    if (x == NORTH && y == SOUTH) return 2;
    if (x == SOUTH && y == NORTH) return 2;
    return 1;
}

int solve() {
    queue<ppp> q; // { {x,y}, {dir,cost} }
    q.push({ {sx,sy},{sd,0} });
    visited[sx][sy][sd] = 0;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if (cost < visited[x][y][d]) continue;
        if (x == ex && y == ey && d == ed) continue;
        // 방향 전환
        for (int k = 1; k <= 4; k++) {
            if (k == d) continue;
            int dc = calDirCost(k, d);
            if (cost + dc < visited[x][y][k]) {
                visited[x][y][k] = cost + dc;
                q.push({{x,y},{k,cost + dc}});
            }
        }
        // 이동
        for (int t = 1; t <= 3; t++) {
            int nx = x + dir[d][0] * t;
            int ny = y + dir[d][1] * t;
            if (nx < 1 || ny < 1 || nx > height || ny > width) break;
            if (map[nx][ny] == 1) break;
            if (cost + 1 < visited[nx][ny][d]) {
                visited[nx][ny][d] = cost + 1;
                q.push({{nx,ny},{d,cost + 1}});
            }
        }
    }
    return visited[ex][ey][ed];
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    cout << solve() << '\n';
    return 0;
}