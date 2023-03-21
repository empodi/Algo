#include <iostream>
#include <algorithm>
using namespace std;
#define LEN 10000

int N;
int A[LEN + 10], B[LEN + 10], sorted[LEN + 10];

bool check() {
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

int solve() {
    int n = 0;
    if (check()) return 1;
    for (int i = N - 1; i >= 0; i--) {
        if (B[i] != sorted[i]){
            n = i;
            break;
        }
        for (int j = 0; j < i; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                if (A[i] == B[i] && check()) return 1;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            swap(A[i], A[i + 1]);
            if (check()) return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        sorted[i] = B[i];
    }
    sort(sorted, sorted + N);
    cout << solve() << '\n';
    return 0;
}