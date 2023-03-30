#include <iostream>
#include <cstring>
#define MAX_ITEM 20
#define MAX_PRICE 10000
using namespace std;

int N, M;
int A[MAX_ITEM + 1];
int dp[MAX_ITEM + 1][MAX_PRICE + 1];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) cin >> A[i];
        cin >> M;
        memset(dp, 0, sizeof (dp));
        for (int i = 1; i <= N; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= M; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= A[i]) dp[i][j] += dp[i][j - A[i]];
            }
        }
        cout << dp[N][M] << '\n';
    }
    return 0;
}
