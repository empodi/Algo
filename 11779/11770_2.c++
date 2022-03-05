#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int vNum, eNum;
int startVertex, endVertex;
vector<vector<pii>> graph(1001, vector<pii>{});
vector<vector<pii>> reverseGraph(1001, vector<pii>{});
int dist[1001];
vector<int> path;

void init() {
    
    cin >> vNum;
    cin >> eNum;
    
    for (int i = 0; i < eNum; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        
        graph[from].push_back({to, cost});
        reverseGraph[to].push_back({from, cost});
    }
    cin >> startVertex >> endVertex;
    
    for (int i = 1; i <= vNum; i++) {
        dist[i] = INT_MAX;
    }
}

int dijkstra() {
    
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {cost, vertex}
    
    pq.push({0, startVertex});
    dist[startVertex] = 0;
    
    while (!pq.empty()) {
        int curVertex = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if (dist[curVertex] < cost) continue;
        
        for (int i = 0; i < graph[curVertex].size(); i++) {
            int nextVertex = graph[curVertex][i].first;
            int nextCost = cost + graph[curVertex][i].second;
            
            if (nextCost < dist[nextVertex]) {
                dist[nextVertex] = nextCost;
                pq.push({nextCost, nextVertex});
            }
        }
    }
    
    return dist[endVertex];
}

void findPath() {
    
    int globalCost = dist[endVertex];
    path.push_back(endVertex);
    
    vector<bool> visited(vNum + 1, false);
    visited[endVertex] = true;
    
    int dest = endVertex;
    while (1) {
        
        for (int i = 0; i < reverseGraph[dest].size(); i++) {
            int vtx = reverseGraph[dest][i].first;
            int localCost = reverseGraph[dest][i].second;
            if (visited[vtx]) continue;
            
            if (dist[vtx] + localCost == globalCost) {
                path.push_back(vtx);
                visited[vtx] = true;
                globalCost -= localCost;
                dest = vtx;
                break;
            }
        }
        
        if (dest == startVertex && globalCost == 0) break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();

    cout << dijkstra() << "\n";
    
    findPath();
    
    cout << path.size() << "\n";
    
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    
    return 0;
}