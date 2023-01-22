#include <bits/stdc++.h>
using namespace std;

#define FIRST 64

int solve(const int& target) {
    
    stack<int> s;
    s.push(FIRST);
    int sum = FIRST;
    
    while (sum != target) {
        
        int len = s.top();
        s.pop();
        
        sum -= len;
        len /= 2;
        
        // 1번 풀이
        if (sum + len < target) {
            s.push(len);
            sum += len;
        }
        
        s.push(len);
        sum += len;
        
        /*  2번 풀이
        if (sum + len >= target) {
            s.push(len);
            sum += len;
        }
        else {
            s.push(len);
            s.push(len);
            sum += len * 2;
        }
        */
    }
    
    return s.size();
}

int main() {
    
    int target;
    scanf("%d", &target);
    
    printf("%d", solve(target));
    
    return 0;
}