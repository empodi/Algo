#include <bits/stdc++.h>
using namespace std;

int musician; 
int pd;
int inDegree[1001] = { 0, };
vector<int> order[1001];
vector<int> answer;

void init() {
    
    cin >> musician >> pd;
    
    for (int i = 0; i < pd; i++) {
        
        int len; cin >> len;
        vector<int> temp;
        
        for (int i = 0; i < len; i++) {
            int val; cin >> val;
            temp.push_back(val);
        }
        
        for (int i = 0; i < len; i++) {
            int cur = temp[i];
            inDegree[cur] += i;
            
            for (int j = i + 1; j < len; j++) {
                order[cur].push_back(temp[j]);
            }
        }
    }
}

bool solve() {
    
    queue<int> q;
    
    for (int i = 1; i <= musician; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        
        int person = q.front();
        q.pop();
        answer.push_back(person);
        
        for (int i = 0; i < order[person].size(); i++) {
            int n = order[person][i];
            
            inDegree[n]--;
            
            if (inDegree[n] == 0) {
                q.push(n);
            }
        }
    }
    
    if (answer.size() == musician) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    if (solve()) {
        for (int i = 0; i < musician; i++) {
            cout << answer[i] << "\n";
        }
    }
    else {
        cout << 0;
    }
    
    return 0;
}