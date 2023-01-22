#include <iostream>
#include <string>
using namespace std;

int A[10] = {0,};

int getTens(int n) { // 10^n
    int ret = 1;
    for (int i = 0; i < n; i++) ret *= 10;
    return ret;
}

void solve(const string& S) {
    for (int i = 0; i < S.length(); i++) {
        int left = i;
        int n = S[i] - '0';
        int right = S.length() - i - 1;
        int leftVal = left == 0 ? 0 : stoi(S.substr(0, left));
        int rightVal = right == 0 ? 0 : stoi(S.substr(left + 1, right));
        //cout << leftVal << ' ' << n << ' ' << rightVal << '\n';

        if (right == 0) {
            for (int j = 1; j <= n; j++) A[j]++;
            if (leftVal) {
                for (int j = 0; j < 10; j++) A[j] += leftVal;
            }
        }
        else if (left == 0) {
            for (int j = 1; j < n; j++) A[j] += getTens(right);
            A[n] += rightVal + 1;
        }
        else {
            A[0] += (leftVal - 1) * getTens(right);
            for (int j = 0; j < n; j++) A[j] += getTens(right) ;
            for (int j = 1; j < 10; j++) A[j] += leftVal * getTens(right);
            A[n] += rightVal + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string S;
    cin >> S;
    solve(S);
    for (int i = 0; i < 10; i++) cout << A[i] << ' ';
    return 0;
}