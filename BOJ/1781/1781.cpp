#include <iostream>
#include <algorithm>
#include <queue>
#define LEN 200000
using namespace std;
typedef pair<int,int> pii;

int N;
struct info {
    int item;
    int deadline;
} A[LEN + 1];

bool cmp(info a, info b) {
    return a.deadline < b.deadline;
}

struct comp {
    bool operator() (info a, info b) {
        return a.item > b.item;
    }
};

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].deadline >> A[i].item;
    }
    sort(A, A + N, cmp);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int aIdx = 0;
    priority_queue< info, vector<info>, comp > pq; 
    for (int day = 1; day <= N && aIdx < N; day++) {
        while (aIdx < N && A[aIdx].deadline <= day) {
            if (pq.size() < day) {
                pq.push({A[aIdx].item, A[aIdx].deadline});
            }
            else if (pq.size() == day && pq.top().item < A[aIdx].item) {
                pq.pop();
                pq.push({A[aIdx].item, A[aIdx].deadline});
            }
            aIdx++;
        }
    }
    long long ret = 0;
    while (!pq.empty()) {
        ret += pq.top().item;
        pq.pop();
    }
    cout << ret << '\n';
    return 0;
}
