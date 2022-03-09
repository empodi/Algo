#include <bits/stdc++.h>
using namespace std;

int vNum;
int eNum;
int parent[500001];

void init() {
    cin >> vNum >> eNum;
    
    for (int i = 1; i <= vNum; i++) {
        parent[i] = i;
    }
}

int findParent(int n) {
    
    if (parent[n] == n) 
        return n;
    else 
        return parent[n] = findParent(parent[n]);
}

bool Union(int x, int y) {
    
    int px = findParent(x);
    int py = findParent(y);
    
    if (px == py) return true;
    
    if (px < py) parent[py] = px;
    else parent[px] = py;
    return false;
}

int solve() {
    
    int cnt = 0;
    
    for (int i = 0; i < eNum; i++) {
        
        int x, y;
        cin >> x >> y;
        cnt++;
        
        if (Union(x, y)) return cnt;
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}