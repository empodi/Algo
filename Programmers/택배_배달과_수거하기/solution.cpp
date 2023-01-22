#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;
    int d = n - 1, p = n - 1;
    while (true)
    {        
        ll mind = -1, minp = -1;
        int amount = cap;
        while (d >= 0)
        {
            if (mind < 0 && deliveries[d]) mind = d;
            if (amount >= deliveries[d])
            {
                amount -= deliveries[d];
                deliveries[d--] = 0;
            }
            else // amount < deliveries[d] 
            {
                deliveries[d] -= amount;   
                break;
            }
        }
        
        amount = cap;
        while (p >= 0)
        {
            if(minp < 0 && pickups[p]) minp = p;
            if (amount >= pickups[p])
            {
                amount -= pickups[p];
                pickups[p--] = 0;
            }
            else // amount < pickups[p]
            {
                pickups[p] -= amount;
                break;
            }
        }
        answer += max(mind + 1,minp + 1) * 2;
        if (max(d,p) < 0) break;
    }
    return answer;
}