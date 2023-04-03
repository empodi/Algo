#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define LEN 10000
#define MAX_DAY 10000
using namespace std;

int N;
struct info {
    int day;
    int money;
};
info A[LEN + 10];

bool cmp(info a, info b) {
    return a.day < b.day;
}

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].money >> A[i].day;
    }
    sort(A, A + N, cmp);
//    cout << "----------------\n";
//    for (int i = 0; i < N; i++) {
//        cout << A[i].day << ' ' << A[i].money << '\n';
//    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();

    int aIdx = 0, ret = 0;
    priority_queue<int, vector<int>, greater<>> pq; // { money, day }
    for (int i = 1; i <= MAX_DAY; i++) {
        while (aIdx < N && A[aIdx].day <= i) {
            if (pq.size() < i) pq.push(A[aIdx].money);
            else if (pq.size() == i && pq.top() < A[aIdx].money) {
                pq.pop();
                pq.push(A[aIdx].money);
            }
            aIdx++;
        }
    }
    while (!pq.empty()) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << '\n';
    return 0;
}
