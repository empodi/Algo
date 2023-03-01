#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0, lo = 0, hi = (int) people.size() - 1;
    while (lo <= hi) {
        answer++;
        if (people[lo] + people[hi] <= limit) {
            lo++;
            hi--;
        }
        else {
            hi--;
        }
    }
    return answer;
}