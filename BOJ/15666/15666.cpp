#include <bits/stdc++.h>
using namespace std;

int len;
int targetLen;
vector<int> v;

void init() {
    
    cin >> len >> targetLen;
    
    for (int i = 0; i < len; i++) {
        int n; cin >> n;
        v.push_back(n);
    }
    
    sort(v.begin(), v.end());
}

void PRINT(vector<int>& target) {
    
    for (auto& t : target) {
        cout << t << " ";
    }
    cout << "\n";
}

void solve(vector<int>& target, int pos) {
    
    if (target.size() == targetLen) {
        PRINT(target);
        return;
    }
    
    for (int i = pos; i < len; i++) {
        
        target.push_back(v[i]);
        
        solve(target, i);
        
        target.pop_back();
        
        while (i + 1 < len && v[i] == v[i + 1])
            i++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    vector<int> target;
    solve(target, 0);
    
    return 0;
}