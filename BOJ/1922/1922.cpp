#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int vNum;
int eNum;
vector<pair<int, pii>> graph;
int parent[1001];

void init() {
    
    cin >> vNum; cin >> eNum;
    
    for (int i = 0; i < eNum; i++) {
        
        int from, to, cost;
        cin >> from >> to >> cost;
        graph.push_back({cost, {from, to}});
    }
    
    sort(graph.begin(), graph.end());
    
    for (int i = 1; i <= vNum; i++) {
        parent[i] = i;
    }
}

int findParent(int x) {
    
    if (x == parent[x]) return x;
    
    parent[x] = findParent(parent[x]);
    
    return parent[x];
}

int solve() {
    
    int cost = 0, curNumOfEdge = 0;
    
    for (int i = 0; i < eNum; i++) {
        
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        
        int px = findParent(x);
        int py = findParent(y);
        
        if (px == py) continue;
        
        if (px < py) parent[py] = px;
        else parent[px] = py;
        
        cost += graph[i].first;
        curNumOfEdge++;
        
        if (curNumOfEdge == vNum - 1) break;
    }

    return cost;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}