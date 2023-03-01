#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int hi = routes[0][1], answer = 1;
    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] <= hi) {
            hi = min(hi, routes[i][1]);
        }
        else {
            answer++;
            hi = routes[i][1];
        }
    }
    return answer;
}