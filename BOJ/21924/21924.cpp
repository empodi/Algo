#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
typedef pair<int, int> pii;
typedef long long ll;

int vNum;
int eNum;
ll totalCost;
vector<pair<int, pii>> v;
int parent[MAX];

void init() {
    
    cin >> vNum >> eNum;
    
    totalCost = 0;
    
    for (int i = 0; i < eNum; i++) {
        
        int x, y, cost;
        cin >> x >> y >> cost;
        
        v.push_back({cost, {x, y}});
        totalCost += cost;
    }
}

int findParent(int n) {
    
    if (n == parent[n]) return n;
    
    return parent[n] = findParent(parent[n]);
}

bool checkConnected() {
    
    int p = findParent(1);
    
    for (int i = 2; i <= vNum; i++) {
        if (p != findParent(i)) 
            return false;
    }
    
    return true;
}

ll solve() {
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i <= vNum; i++) {
        parent[i] = i;
    }
    
    ll cost = 0;
    
    for (int i = 0; i < eNum; i++) {
        
        int x = v[i].second.first;
        int y = v[i].second.second;
        
        int px = findParent(x);
        int py = findParent(y);
        
        if (px == py) continue;
        
        if (px < py) parent[py] = px;
        else parent[px] = py;

        cost += v[i].first;
    }
    
    if (checkConnected()) {
        return totalCost - cost;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}