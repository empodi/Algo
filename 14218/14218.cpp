#include <bits/stdc++.h>
using namespace std;

#define MAX 987654321

typedef pair<int, int> pii;

int vNum;
int eNum;
int roads;

vector<int> graph[1001];
int dist[1001];

void init() {
    
    cin >> vNum >> eNum;
    
    for (int i = 0; i < eNum; i++) {
        
        int x, y;
        cin >> x >> y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    cin >> roads;
}

void setDist() {
    
    for (int i = 0; i <= vNum; i++) {
        dist[i] = MAX;
    }
}

void Dijkstra() {
    
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {cost, vertex}
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        
        int vtx = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if (dist[vtx] < cost) continue;
        
        for (int i = 0; i < graph[vtx].size(); i++) {
            
            int next = graph[vtx][i];
            int nextCost = cost + 1;
            
            if (nextCost < dist[next]) {
                
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

void solve() {
    
    while (roads--) {
        
        setDist();
        
        int x, y;
        
        cin >> x >> y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
        
        Dijkstra();
        
        for (int i = 1; i <= vNum; i++) {
            
            if (dist[i] == MAX) cout << -1;
            else cout << dist[i];
            cout << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    solve();
    
    return 0;
}