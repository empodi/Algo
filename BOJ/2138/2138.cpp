#include <iostream>
#include <algorithm>
using namespace std;
#define LEN 100000

int N;
int A[LEN + 1] = {0,}, B[LEN + 1] = {0,}, C[LEN + 1] = {0,};

void get_input() {
    cin >> N;
    string s;
    cin >> s;
    for (int i = 0; i < N; i++) A[i] = B[i] = s[i] - '0';
    cin >> s;
    for (int i = 0; i < N; i++) C[i] = s[i] - '0';
}

void change(const int & idx, int arr[]) {
    for (int i = idx - 1; i < idx + 2; i++) {
        if (i < 0 || i >= N) continue;
        arr[i] = 1 - arr[i];
    }
}

bool check(const int arr[]) {
    for (int i = 0; i < N; i++) {
        if (arr[i] != C[i]) return false;
    }
    return true;
}

int firstCheck() {
    int ret = 1;
    change(0, A);
    for (int i = 1; i < N; i++) {
        if (A[i - 1] != C[i - 1]) {
            change(i, A);
            ret++;
        }
    }
    return check(A) ? ret : -1;
}

int secondCheck() {
    int ret = 0;
    for (int i = 1; i < N; i++) {
        if (B[i - 1] != C[i - 1]) {
            change(i, B);
            ret++;
        }
    }
    return check(B) ? ret : -1;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    int x = firstCheck();
    int y = secondCheck();
    if (x >= 0 && y >= 0) cout << min(x, y) << '\n';
    else if (x < 0 && y < 0) cout << -1 << '\n';
    else cout << max(x, y) << '\n';
    return 0;
}