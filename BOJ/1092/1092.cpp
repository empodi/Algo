#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> cList;
vector<int> bList;

int solve() {
    if (bList[0] > cList[0]) return -1;
    int ret = 0, cnt = 0;
    while (cnt < M) {
        int cIdx = 0;
        for (int i = 0; i < M && cIdx < N; i++) {
            if (bList[i] == 0) continue;
            if (bList[i] <= cList[cIdx]) {
                bList[i] = 0;
                cnt++;
                cIdx++;
            }
        }
        ret++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    cList.resize(N);
    for (int i = 0; i < N; i++) cin >> cList[i];
    cin >> M;
    bList.resize(M);
    for (int i = 0; i < M; i++) cin >> bList[i];
    sort(cList.begin(), cList.end(), greater<>());
    sort(bList.begin(), bList.end(), greater<>());
    cout << solve() << '\n';
    return 0;
}