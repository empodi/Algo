#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int vNum;
int eNum;
int range;
vector<pii> graph[101];    // {dest, cost}
int items[101];

void init() {
    
    cin >> vNum >> range >> eNum;
    
    for (int i = 1; i <= vNum; i++) {
        cin >> items[i];
    }
    
    for (int i = 0; i < eNum; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }
}

int getCostByDijkstra(int start) {
    
    int ret = 0;
    vector<int> dist(vNum + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;    // {cost, vertex}
    
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        
        int vtx = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if (dist[vtx] < cost) continue;
        
        for (int i = 0; i < graph[vtx].size(); i++) {
            int next = graph[vtx][i].first;
            int nextCost = graph[vtx][i].second + cost;
            
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    
    for (int i = 1; i <= vNum; i++) {
        if (dist[i] <= range)
            ret += items[i];
    }
    
    return ret;
}

int solve() {
    
    int answer = 0;
    
    for (int i = 1; i <= vNum; i++) {
        
        answer = max(answer, getCostByDijkstra(i));
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}