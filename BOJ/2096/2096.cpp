#include <bits/stdc++.h>
using namespace std;

int minTable[2][3];
int maxTable[2][3];
int len;

int threeMin(int a, int b, int c) {
    a = a < b ? a : b;
    return a < c ? a : c;
}
int threeMax(int a, int b, int c) {
    a = a > b ? a : b;
    return a > c ? a : c;
}

void copyToFirstRow() {
    
    for (int i = 0; i < 3; i++) {
        minTable[0][i] = minTable[1][i];
        maxTable[0][i] = maxTable[1][i];
    }
}

void copyMinToMax(int idx) {
    
    for (int i = 0; i < 3; i++) {
        maxTable[idx][i] = minTable[idx][i];
    }
}

void setMax() {
    int a = max(maxTable[0][0], maxTable[0][1]);
    int b = threeMax(maxTable[0][0], maxTable[0][1], maxTable[0][2]);
    int c = max(maxTable[0][1], maxTable[0][2]);
    
    maxTable[0][0] = a;
    maxTable[0][1] = b;
    maxTable[0][2] = c;
}

void setMin() {
    int a = min(minTable[0][0], minTable[0][1]);
    int b = threeMin(minTable[0][0], minTable[0][1], minTable[0][2]);
    int c = min(minTable[0][1], minTable[0][2]);
    
    minTable[0][0] = a;
    minTable[0][1] = b;
    minTable[0][2] = c;
}

void solve() {
    
    cin >> minTable[0][0] >> minTable[0][1] >> minTable[0][2];
    copyMinToMax(0);
    
    for (int i = 1; i < len; i++) {
        cin >> minTable[1][0] >> minTable[1][1] >> minTable[1][2];
        copyMinToMax(1);
        
        setMax();
        setMin();
        
        for (int k = 0; k < 3; k++) {
            minTable[1][k] += minTable[0][k];
            maxTable[1][k] += maxTable[0][k];
        }
        
        copyToFirstRow();
    }
    
    cout << threeMax(maxTable[0][0], maxTable[0][1], maxTable[0][2]) << " ";
    cout << threeMin(minTable[0][0], minTable[0][1], minTable[0][2]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> len;
    
    solve();
    
    return 0;
}