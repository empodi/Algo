#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

queue<pii> q;
int height, width;
int map[1001][1001] = {0,};
int visited[1001][1001] = {0,};
int dir[8][2] = { {1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1} };

void get_input()
{
    cin >> height >> width;
    for (int i = 0; i < height; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < width; j++) map[i][j] = s[j] == '.' ? 0 : s[j] - '0';
    }
}

void firstFill() // Q에 처음으로 삽입할 위치
{
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            if (map[i][j]) continue;
            visited[i][j] = 1;
            for (int k = 0; k < 8; k++)
            {
                int ni = i + dir[k][0], nj = j + dir[k][1];
                if (ni < 0 || nj < 0 || ni >= height || nj >= width) continue;
                if (map[ni][nj])
                {
                    q.push({i,j});
                    break;
                }
            }
        }
    }
}

int solve()
{
    firstFill();
    int ret = 0;
    while (true)
    {
        queue<pii> tempQ;
        while (q.size())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 8; k++)
            {
                int nx = x + dir[k][0], ny = y + dir[k][1];
                if (nx < 0 || ny < 0 || nx >= height || ny >= width) continue;
                if (visited[nx][ny] || map[nx][ny] == 0) continue;
                visited[x][y] = true;
                if (map[nx][ny] > 0) map[nx][ny]--;
                if (map[nx][ny] == 0) tempQ.push({nx,ny});
            }
        }
        if (tempQ.size() == 0) break;
        ret++;
        swap(tempQ, q);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    cout << solve() << '\n';
    return 0;
}