#include <cstdlib>
#include <iostream>
using namespace std;

int height;
int width;
char board[21][21];
bool isUsed[26]; // 알파벳이 사용되었는지 여부 판단
int answer = 0;
int moving[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void init() 
{
    cin >> height >> width;
    for (int i = 0; i < height; i++) 
    {
        string str;
        cin >> str;
        for (int j = 0; j < width; j++) board[i][j] = str[j];
    }
}

void DFS(int i, int j, int curLen) 
{
    if (curLen > answer) answer = curLen;
    for (int k = 0; k < 4; k++) 
    {
        int x = i + moving[k][0];
        int y = j + moving[k][1];
        if (x < 0 || y < 0 || x >= height || y >= width || isUsed[board[x][y] - 'A']) continue;
        isUsed[board[x][y] - 'A'] = true;
        DFS(x, y, curLen + 1);
        isUsed[board[x][y] - 'A'] = false;
    }
}


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    isUsed[board[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << answer << '\n';
    return 0;
}