#include <cstdlib>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int V, E, ret = INT_MAX;
int graph[401][401];

void get_input()
{
    cin >> V >> E;
    for (int i = 0; i <= V; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }
    for (int i = 0 ; i < E; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        graph[x][y] = c;
    }
}

int solve()
{
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    int ret = INT_MAX;
    for (int i = 1; i <= V; i++)
    {
        ret = min(ret, graph[i][i]);
    }
    return ret == INT_MAX ? -1 : ret;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    cout << solve() << '\n';
    return 0;
}