#include <iostream>
#include <algorithm>
#include <cstring>
#define LEN 100000
using namespace std;

int N, pos, neg;
int A[LEN + 1], B[LEN + 1], C[LEN + 1];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    cin >> N;
    for (int i = 1 ; i <= N; i++) {
        cin >> A[i];
        if (A[i] == 2) A[i] = -1;
    }
    pos = neg = 0;
    for (int i = 1; i <= N; i++) {
        B[i] = max(A[i], B[i - 1] + A[i]);
        C[i] = min(A[i], C[i - 1] + A[i]);
        pos = max(pos, B[i]);
        neg = min(neg, C[i]);
    }
    cout << max(abs(pos), abs(neg)) << '\n';
    return 0;
}
