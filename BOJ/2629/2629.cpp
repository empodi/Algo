#include <iostream>
using namespace std;
#define MAX_NUM 30
#define MAX_WEIGHT 40000

int N, M;
int dp[MAX_NUM + 10][MAX_WEIGHT + 10] = {0,};
int A[MAX_NUM + 10];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 0; i <= MAX_NUM; i++) dp[i][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= MAX_WEIGHT; j++) {
            if (dp[i - 1][j]) {
                dp[i][j] = 1;
            }
            else {
                int target = abs(j - A[i]);
                if (target <= MAX_WEIGHT && dp[i - 1][target]) dp[i][j] = 1;
                target = j + A[i];
                if (target <= MAX_WEIGHT && dp[i - 1][target]) dp[i][j] = 1;
            }
        }
    }
    cin >> M;
    while (M--) {
        int w;
        cin >> w;
        if (dp[N][w]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}