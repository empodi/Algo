#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int N, M, S, D, minDist;
int dist[501];
int cache[501][501] = {0,};
vector<pii> graph[501];
vector<int> pre[501];
bool visited[501];
const int MAX = 654321;

void init()
{
    for (int i = 0; i < 501; i++) { 
        graph[i].clear(); visited[i] = false; 
        pre[i].clear();
    }
    cin >> S >> D;
    for (int i=0;i<501;i++) for (int j=0;j<501;j++) { cache[i][j] = 0; }
    for (int i = 0; i < M; i++)
    {
        int x,y,c;
        cin >> x >> y >> c;
        graph[x].push_back({y,c});
        cache[x][y] = graph[x].size() - 1;
    }
}

void dijkstra()
{
    for (int i = 0; i <= N; i++) dist[i] = MAX;
    dist[S] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push({0,S});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (cost > dist[cur]) continue;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nextCost = graph[cur][i].second;
            if (next < 0) continue;
            if (cost + nextCost == dist[next]) pre[next].push_back(cur);
            if (cost + nextCost < dist[next]) 
            {
                dist[next] = cost + nextCost;
                pq.push({dist[next], next});
                pre[next].clear();
                pre[next].push_back(cur);
            }
        }
    }
    minDist = dist[D];
}

void bfs_backtrack() {
    queue<int> q;
    q.push(D);
    visited[D] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto& e : pre[x]) {
            graph[e][cache[e][x]].first = -1;
            if (visited[e]) continue;
            visited[e] = true;
            if (e != S)
                q.push(e);
        }
    }
}

int solve()
{
    dijkstra();
    bfs_backtrack();
    dijkstra();
    if (dist[D] == MAX) return -1;
    else return dist[D];
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while (true)
    {
        cin >> N >> M;
        if (max(N,M) == 0) break;
        init();
        cout << solve() << '\n';
    }
    return 0;
}