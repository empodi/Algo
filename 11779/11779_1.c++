#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int vNum, eNum;
int startVertex, endVertex;
vector<vector<pii>> graph(1001, vector<pii>{});
int dist[1001];
int path[1001];
vector<int> answerPath;

void init() {
    
    cin >> vNum;
    cin >> eNum;
    
    for (int i = 0; i < eNum; i++) {
        int from, to;
        int cost;
        cin >> from >> to >> cost;
        
        graph[from].push_back({to, cost});
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
    path[startVertex] = 0;
    
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
                path[nextVertex] = curVertex;
            }
        }
    }
    
    int temp = endVertex;
    
    while (temp) {
        answerPath.push_back(temp);
        temp = path[temp];
    }
    
    return dist[endVertex];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();

    cout << dijkstra() << "\n";
    
    cout << answerPath.size() << "\n"; 
   
    for (int i = answerPath.size() - 1; i >= 0; i--) {
        cout << answerPath[i] << " ";
    }
    
    return 0;
}