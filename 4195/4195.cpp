#include <bits/stdc++.h>
using namespace std;

int len;
int parent[300000];
int setSize[300000];

void init(){
    
    cin >> len;
    
    for (int i = 0; i <= len * 2; i++){
        parent[i] = i;
        setSize[i] = 1;
    }
}

int findParent(int n) {
    
    if (parent[n] == n){
        return n;
    }
    else {
        return parent[n] = findParent(parent[n]);
    }
}

void setParent(const int& xp, const int& yp) {
    
    if (setSize[xp] < setSize[yp]) {
        parent[xp] = parent[yp];
        setSize[yp] += setSize[xp];
        setSize[xp] = 0;
    }
    else {
        parent[yp] = parent[xp];
        setSize[xp] += setSize[yp];
        setSize[yp] = 0;
    }
}

void solve() {
    
    init();
    
    unordered_map<string, int> hash;
    int cnt = 0;    // num of friends
    
    for (int i = 0; i < len; i++) {
        
        string x, y;
        cin >> x >> y;
        
        if (hash.find(x) == hash.end()) {
            hash.insert({x, ++cnt});
        }
        
        if (hash.find(y) == hash.end()) {
            hash.insert({y, ++cnt});
        }
        
        int xp = findParent(hash[x]);
        int yp = findParent(hash[y]);
        
        if (xp != yp) {
            setParent(xp, yp);
            cout << max(setSize[xp], setSize[yp]) << "\n";
        }
        else {
            cout << max(setSize[xp], setSize[yp]) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        
        solve();
    }
    
    return 0;
}