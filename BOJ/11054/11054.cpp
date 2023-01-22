#include <bits/stdc++.h>
using namespace std;

int len;
int arr[1001];
int dpForward[1001];
int dpBackward[1001];

void init() {
    
    cin >> len;
    
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
}

void setVector(vector<int>& v, int n) {
    
    if (v.empty() || n > v.back()) {
        v.push_back(n);
    }
    else {
        auto it = lower_bound(v.begin(), v.end(), n);
        *it = n;
    }
}

void setForwardDP() {
    
    vector<int> v;
    
    for (int i = 0; i < len; i++) {
        setVector(v, arr[i]);
        dpForward[i] = v.size();
    }
}

void setBackwardDP() {
    
    vector<int> v;
    
    for (int i = len - 1; i >= 0; i--) {
        setVector(v, arr[i]);
        dpBackward[i] = v.size();
    }
}

int solve() {
    
    setForwardDP();
    setBackwardDP();
    
    int ans = 0;
    
    for (int i = 0; i < len; i++) {
        
        int val = dpForward[i] + dpBackward[i] - 1;
        ans = ans > val ? ans : val;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    cout << solve();
    
    return 0;
}