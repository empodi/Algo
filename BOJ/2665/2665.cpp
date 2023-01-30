#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 987654321
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

const int BLACK = 0;
const int WHITE = 1;

int N;
int map[51][51] = {0,};
int dist[51][51];
int dir[4][2] = { {1,0}, {-1,0}, {0,-1}, {0,1} };

void get_input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) map[i][j + 1] = s[j] - '0';
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) dist[i][j] = MAX;
    }
}

int solve()
{
    priority_queue< pip, vector<pip>, greater<pip> > pq;
    dist[1][1] = map[1][1] == BLACK ? 1 : 0;
    pq.push({ dist[1][1], {1,1} });
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            int nCost = map[nx][ny] == BLACK ? 1 : 0;
            if (cost + nCost < dist[nx][ny])
            {
                dist[nx][ny] = cost + nCost;
                pq.push({ dist[nx][ny], {nx, ny} });
            }
        }
    }
    return dist[N][N];
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    cout << solve() << '\n';
    return 0;
}