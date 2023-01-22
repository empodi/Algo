#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int vNum;
int eNum;
int party;

vector<pii> graph[1001];
int goToParty[1001];
int dist[1001];

void init() {
    
    cin >> vNum >> eNum >> party;
    
    for (int i = 0; i < eNum; i++) {
        
        int x, y, cost;
        cin >> x >> y >> cost;
        
        graph[x].push_back({y, cost});
    }
}

int Dijkstra(const int& start) {
    
    for (int i = 1; i <= vNum; i++) {
        dist[i] = INT_MAX;
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {cost, vertex}
    
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        
        int cost = pq.top().first;
        int vtx = pq.top().second;
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
    
    return dist[party];
}

int solve() {
    
    int ret = 0;
    
    for (int i = 1; i <= vNum; i++) {
        
        goToParty[i] = Dijkstra(i); // 각 마을에서 파티에 가는 거리 저장
    }
    
    Dijkstra(party);    // dist 배열에 돌아오는 최단 거리 저장
    
    for (int i = 1; i <= vNum; i++) {
        
        int val = goToParty[i] + dist[i];
        ret = max(ret, val);
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}