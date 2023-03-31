#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, K, A[MAX + 1];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> K;
    int start = 0;
    while (K > 0 && start < N) {
        int maxVal = A[start];
        int maxIdx = start;
        for (int i = start + 1; i < min(N, start + K + 1); i++) {
            if (A[i] > maxVal) {
                maxVal = A[i];
                maxIdx = i;
            }
        }

        // SWAP 할 게 없으면 위 for문에서 maxIdx == start로 결과 도출
        for (int i = maxIdx; i > start; i--) 
            swap(A[i], A[i - 1]);
        K -= (maxIdx - start);

        start++;
    }
    for (int i = 0; i < N; i++) cout << A[i] << ' ';
    return 0;
}
