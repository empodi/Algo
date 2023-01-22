#include <bits/stdc++.h>
using namespace std;

int gates;
int planes;
int parent[100001];

void init() {
    cin >> gates;
    cin >> planes;
    
    for (int i = 1; i <= gates; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

void union_parent(int x, int y) {
    
    int px = find(x);
    int py = find(y);
    
    if (px < py) parent[py] = px;
    else parent[px] = py;
}

int solve() {
    
    int answer = 0;
    
    for (int i = 1; i <= planes; i++) {
        
        int x;
        cin >> x;
        
        int dock = find(x);
        
        if (dock == 0) return answer;
        
        union_parent(dock, dock - 1);
        answer++;
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