#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int sNum;
int ladNum;
unordered_map<int, int> snake;
unordered_map<int, int> ladder;
bool visited[101];

void init() {
    
    cin >> ladNum >> sNum;
    
    for (int i = 0; i < ladNum; i++) {
        
        int x, y;
        cin >> x >> y;
        
        if (x > y) swap(x, y);
        
        ladder.insert({x, y});
    }
    
    for (int i = 0; i < sNum; i++) {
        
        int x, y;
        cin >> x >> y;
        
        if (x < y) swap(x, y);
        
        snake.insert({x, y});
    }
}

int BFS() {
    
    int answer = INT_MAX;
    
    queue<pii> q;
    q.push({1, 0});
    visited[1] = true;
    
    while (!q.empty()) {
        
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (pos == 100) {
            answer = min(answer, cnt);
            continue;
        }
        
        for (int i = 1; i <= 6; i++) {
            
            int next = pos + i;
        
            if (next > 100 || visited[next]) continue;
            
            visited[next] = true;
            
            auto it = snake.find(next);
            
            if (it != snake.end()) {
                q.push({it->second, cnt + 1});
                continue;
            }
            
            it = ladder.find(next);
            
            if (it != ladder.end()) {
                q.push({it->second, cnt + 1});
                continue;
            }
            
            q.push({next, cnt + 1});
        }
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << BFS();
    
    return 0;
}