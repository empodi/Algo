#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    string S = "0";
    while (N--) {
        if (S == "9876543210") {
            S = "-1";
            break;
        }
        int i = (int) S.length() - 1;
        while (i > 0) {
            if (S[i - 1] > S[i] + 1) {
                S[i]++;
                int n = 0;
                for (int j = (int) S.length() - 1; j > i; j--) {
                    S[j] = (n++) + '0';
                }
                break;
            }
            i--;
        }
        if (i == 0) {
            if (S[0] == '9') {
                string tmp;
                for (int j = S.length(); j >= 0; j--) {
                    tmp += to_string(j);
                }
                S = tmp;
            }
            else {
                S[0]++;
                for (int j = 1; j < S.length(); j++) {
                    S[j] = (S.length() - j - 1) + '0';
                }
            }
        }
    }
    cout << S << '\n';
    return 0;
}
