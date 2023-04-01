#include <iostream>
#include <vector>
#include <algorithm>
#define LEN 50
#define MAX 987654321
using namespace std;

string S;
int N;
int dp[LEN + 5];
vector<string> v;

void init() {
    cin >> S;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    fill (dp, dp + LEN + 1, MAX);
}

int check(const string & s, const string & t) {
    string p = s, q = t;
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    if (p != q) return MAX;
    int ret = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) ret++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    for (int i = 0; i < S.length(); i++) {
        for (int j = i; j < S.length(); j++) {
            int curLen = j - i + 1;
            string tmp = S.substr(i, curLen);
            for (auto & e : v) {
                if (e.length() == curLen) {
                    int res = check(tmp, e);
                    if (i == 0) dp[j] = min(dp[j], res);
                    else dp[j] = min(dp[j], dp[i - 1] + res);
                }
            }
        }
    }
//    for (int i = 0; i < S.length(); i++) cout << dp[i] << ' '; cout << '\n';
    if (dp[S.length() - 1] == MAX) cout << "-1 \n";
    else cout << dp[S.length() - 1] << '\n';
    return 0;
}
