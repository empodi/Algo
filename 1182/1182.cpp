#include <bits/stdc++.h>
using namespace std;

int len;
int target;
int answer;
vector<int> v;

void init() {
    
    cin >> len >> target;
    
    for (int i = 0; i < len; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    answer = 0;
}

void solve(int cnt, int pos, int sum) {
    
    if (pos == len) {
        if (cnt > 0 && sum == target) answer++;
        return;
    }
    
    solve(cnt, pos + 1, sum);
    solve(cnt + 1, pos + 1, sum + v[pos]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    solve(0, 0, 0);
    
    cout << answer;
    
    return 0;
}