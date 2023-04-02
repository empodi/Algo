#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define LEN 100000
using namespace std;

int N;
struct info {
    int id;
    int start;
    int end;
};
info A[LEN + 10];

bool cmp(info a, info b) {
    return a.start < b.start;
}

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].id >> A[i].start >> A[i].end;
    }
    sort(A, A + N, cmp);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();

    int ret = 0;
    priority_queue<int, vector<int>, greater<>> pq; // end
    for (int i = 0; i < N; i++) {
        while (!pq.empty() && A[i].start >= pq.top()) pq.pop();
        pq.push(A[i].end);
        ret = max(ret, (int) pq.size());
    }
    cout << ret << '\n';
    return 0;
}
