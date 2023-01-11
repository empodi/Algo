#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, E;
bool isCycle;
vector<int> graph[1001];
bool visited[1001];
bool edges[1001][1001];

void get_input()
{
    cin >> V;
    cin >> E;
    for (int i = 1; i <= V; i++) graph[i].clear();
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(edges, false, sizeof(edges));
    isCycle = false;
}

void dfs(int cur)
{
    if (visited[cur]) 
    {
        isCycle = true;
        return;
    }
    visited[cur] = true;
    for (int e : graph[cur])
    {
        if (!edges[cur][e] && !edges[cur][e])
        {
            edges[cur][e] = edges[e][cur] = true;
            dfs(e);
        }
    }
}

bool checkConnected()
{
    int cnt = 0;
    for (int i = 1; i <= V; i++) 
        if (visited[i]) cnt++;
    return cnt == V;
}

string solve()
{
    if (E + 1 != V) return "graph";
    dfs(1);
    if (isCycle || !checkConnected()) return "graph";
    return "tree";
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        get_input();
        cout << solve() << '\n';
    }
    return 0;
}