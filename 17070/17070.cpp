#include <bits/stdc++.h>
using namespace std;

int N;
int board[17][17];
int answer;

void init() {
    
    answer = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

int getDirection(int x1, int y1, int x2, int y2) {
    /*
    return
    0 -> 가로
    1 -> 세로
    2 -> 대각선
    */
    if (x1 == x2) return 0;
    if (y1 == y2) return 1;
    return 2;
}

void DFS(int x1, int y1, int x2, int y2) {
    
    if (x2 >= N || y2 >= N)
        return;
    
    int direction = getDirection(x1, y1, x2, y2);
    
    if (board[x2][y2] == 1) return;
    
    if (direction == 2 && (board[x1 + 1][y1] || board[x1][y1 + 1]))
        return;
    
    if (x2 == N - 1 && y2 == N - 1) {
        answer++;
        return;
    }
    
    DFS(x2, y2, x2 + 1, y2 + 1);    // 현재 파이프 방향 상관 없이 항상 대각선 이동 가능
    
    switch (direction) {
        case 0:
            DFS(x2, y2, x2, y2 + 1);
            break;
        case 1:
            DFS(x2, y2, x2 + 1, y2);
            break;
        case 2:
            DFS(x2, y2, x2, y2 + 1);
            DFS(x2, y2, x2 + 1, y2);
            break;
    }
}

int main() {
    ios::sync_with_stdio(0);    
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    DFS(0, 0, 0, 1);
    
    cout << answer;
    
    return 0;
}