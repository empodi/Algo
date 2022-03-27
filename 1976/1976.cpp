#include <bits/stdc++.h>
using namespace std;

int vNum;
int pNum;
bool city[201][201];
int plan[1001];
int parent[201];

void init() {
    
    cin >> vNum;
    cin >> pNum;
    
    for (int i = 1; i <= vNum; i++) {
        for (int j = 1; j <= vNum; j++) {
            cin >> city[i][j];
        }
    }
    
    for (int i = 0; i < pNum; i++) {
        cin >> plan[i];
    }
    
    for (int i = 0; i <= vNum; i++) {
        parent[i] = i;
    }
}

int findParent(int n) {
    
    if (n == parent[n]){
        return n;
    }
    else
        return parent[n] = findParent(parent[n]);
}

void setParent() {
    
    for (int i = 1; i <= vNum; i++) {
        for (int j = 1; j <= vNum; j++) {
            
            if (city[i][j] == 0) continue;
            
            int pi = findParent(i);
            int pj = findParent(j);
            
            if (pi < pj) {
                parent[pj] = pi;
            }
            else if (pi > pj){
                parent[pi] = pj;
            }
        }
    } 
}

bool isAvailable() {
    
    int p = parent[plan[0]];
    
    for (int i = 1; i < pNum; i++) {
        if (p != parent[plan[i]])
            return false;
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    setParent();
    
    if (isAvailable()) {
        cout << "YES";
    }
    else cout << "NO";
    
    return 0;
}