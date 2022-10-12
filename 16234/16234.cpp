#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int N,L,R;
int map[55][55] = {0,};
bool visited[55][55];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void get_input()
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}

void setVisited()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = false;
}

void printMap() {
    cout << "-----------------------------------------------------\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) cout << map[i][j] << " ";
        cout << endl;
    }
}

bool checkBFS(int& x, int& y) // BFS 탐색 필요가 있을 경우 true 반환
{
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dir[k][0];
        int ny = y + dir[k][1];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        int diff = abs(map[nx][ny] - map[x][y]);
        if (diff >= L && diff <= R) return true;
    }
    return false;
}

int solve()
{
    int ret = 0;
    while (true)
    {
        bool flag = false;
        setVisited();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && checkBFS(i,j))
                {
                    queue<pii> q;
                    queue<pii> pos;
                    q.push({i,j});
                    pos.push({i,j});
                    visited[i][j] = true;
                    int sum = map[i][j];
                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dir[k][0];
                            int ny = y + dir[k][1];
                            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            if (visited[nx][ny]) continue;
                            int diff = abs(map[x][y] - map[nx][ny]);
                            if (diff >= L && diff <= R)
                            {
                                visited[nx][ny] = true;
                                flag = true;
                                q.push({nx,ny});
                                pos.push({nx,ny});
                                sum += map[nx][ny];
                            }
                        }
                    }
                    int avg = sum / pos.size();
                    while (!pos.empty())
                    {
                        int x = pos.front().first;
                        int y = pos.front().second;
                        pos.pop();
                        map[x][y] = avg;
                    }
                }
            }
        }
        if (!flag) break;
        //printMap();
        ret++;
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
