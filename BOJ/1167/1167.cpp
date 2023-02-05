#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
typedef pair<int,int> pii;

bool visited[100001];
int maxDist = 0;
int vertex = 0;

void DFS(vector<vector<pii>>& graph, int v, int dist) {
    if (visited[v]) return;
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
        int nextV = graph[v][i].first;
        int newDist = graph[v][i].second + dist;
        if (visited[nextV]) continue;
        if (newDist > maxDist) {
            vertex = nextV;
            maxDist = newDist;
        }
        DFS(graph, nextV, newDist);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int vNum;
    cin >> vNum;
    vector<vector<pii>> graph(vNum + 1, vector<pii>{}); // {vertex, cost}
    for (int i = 0; i < vNum; i++) {
        int x, y, c;
        cin >> x;
        while (1) {
            cin >> y;
            if (y < 0) break;
            cin >> c;
            graph[x].push_back({y, c});
            graph[y].push_back({x, c});
        }
    }
    memset(visited, false, sizeof(visited));
    DFS(graph, 1, 0);
    memset(visited, false, sizeof(visited));
    DFS(graph, vertex, 0);
    cout << maxDist;
    return 0;
}