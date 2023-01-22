#include <cstdlib>
#include <iostream>
#include <deque>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
using namespace std;
typedef pair<int,int> pii;

int len;
int map[101][101] = {0,};
int snake[101][101] = {0,};
deque<pii> dq;

void get_input() {
    cin >> len;
    int a; 
    cin >> a;
    while (a--) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    int direct;
    cin >> direct;
    while (direct--) {
        int x;
        char c;
        cin >> x >> c;
        dq.push_back({x, c});
    }
}

int change_dir(int dir, char c) {
    if (c == 'D') dir++;
    else dir = dir - 1 < 0 ? 3 : dir - 1;
    return dir % 4;
}

bool move(deque<pii>& body, int dir) {
    int dx = 0, dy = 0;
    if (dir == UP) dx--;
    else if (dir == RIGHT) dy++;
    else if (dir == DOWN) dx++;
    else dy--;
    
    int nx = body.back().first + dx; 
    int ny = body.back().second + dy;
    if (nx < 1 || ny < 1 || nx > len || ny > len || snake[nx][ny]) return false;
    body.push_back({nx, ny});
    snake[nx][ny] = 1;
    
    if (!map[nx][ny]) {
        snake[body.front().first][body.front().second] = 0;
        body.pop_front();
    }
    else map[nx][ny] = 0;
    
    return true;
}

int solve() {
    int time = 0;
    int dir = RIGHT;
    deque<pii> body;
    body.push_back({1,1});
    snake[1][1] = 1;
    
    while (true) {
        time++;
        if (!move(body, dir)) break;
        if (!dq.empty() && dq.front().first == time) {
            dir = change_dir(dir, dq.front().second);
            dq.pop_front();
        }
    }
    return time;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    cout << solve() << '\n';
    return 0;
}