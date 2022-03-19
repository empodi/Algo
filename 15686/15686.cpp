#include <bits/stdc++.h>
using namespace std;

#define MAX 989898
typedef pair<int, int> pii;

int len;
int limit;
int cNum; // 치킨 집 총 개수
vector<pii> house;
vector<pii> chicken;
int answer;

void init() {
    
    cin >> len >> limit;
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            
            int x;
            cin >> x;
            
            if (x == 1) {
                house.push_back({i, j});
            }
            else if (x == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    
    cNum = chicken.size();
    answer = INT_MAX;
}

int getMinDistance(vector<pii>& stores) {
    
    int globalCost = 0;
    
    for (auto& h : house) {
        
        int localCost = MAX;
        
        for (auto& s : stores) {
            int cost = abs(s.first - h.first) + abs(s.second - h.second);
            
            localCost = cost < localCost ? cost : localCost;
        }
        
        globalCost += localCost;
    }
    
    return globalCost;
}

void solve(vector<pii>& stores, int pos) {
    
    if (stores.size() == limit) {
        
        answer = min(answer, getMinDistance(stores));
        return;
    }
    
    for (int i = pos; i < cNum; i++) {
        
        stores.push_back({chicken[i].first, chicken[i].second});
        solve(stores, i + 1);
        stores.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    vector<pii> stores;
    solve(stores, 0);
    
    cout << answer;
    
    return 0;
}