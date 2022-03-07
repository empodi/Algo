#include <bits/stdc++.h>
using namespace std;

int problems;
int infos;
vector<int> order[32001];
int inDegree[32001] = { 0, };
vector<int> answer;

void init() {
    cin >> problems >> infos;
    
    for (int i = 0; i < infos; i++) {
        int x, y;
        cin >> x >> y;
        inDegree[y]++;
        order[x].push_back(y);
    }
}

void solve() {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 1; i <= problems; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);   
        }
    }
    
    while (!pq.empty()) {
        
        int cur = pq.top();
        pq.pop();
        
        answer.push_back(cur);
        
        for (int i = 0; i < order[cur].size(); i++) {
            
            int next = order[cur][i];
            
            inDegree[next]--;
            
            if (inDegree[next] == 0)
                pq.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    solve();
    
    for (auto& c : answer) {
        cout << c << " ";
    }
    
    return 0;
}