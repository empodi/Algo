#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int vNum;
int eNum;
int parent[10010]; // union find
vector<pair<int,pii>> graph;

void init() {
    
     cin >> vNum >> eNum;
    
    for (int i = 0; i < eNum; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph.push_back({cost, {from, to}});
    }
    
    for (int i = 1; i <= vNum; i++) {
        parent[i] = i;
    }
    
    sort(graph.begin(), graph.end());
}

int findParent(int x) {
    
    if (parent[x] == x) return x;
    else return findParent(parent[x]);
}

int solve() {
    
    int cost = 0;
    int numOfEdge = 0;
        
    for (int i = 0; i < eNum; i++) {
            
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        
        int p_x = findParent(x);
        int p_y = findParent(y);
            
        if (p_x != p_y) {
            cost += graph[i].first;   
            
            if (p_x < p_y) parent[p_y] = p_x;
            else parent[p_x] = p_y;
        }
        
        if (numOfEdge == vNum - 1)
            break;
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