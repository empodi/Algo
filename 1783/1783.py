import sys
input = sys.stdin.readline
N, M = map(int, input().split())

def solve():
    global N, M
    if min(N,M) == 1 or max(N,M) <= 2:
        return 1
    if N >= 3 and M >= 7:
        return M - 2
    else:
        N, M, ret = min(N,7), min(M,7), 1
        dp = [[0 for i in range(10)] for _ in range(10)]
        dp[1][1] = 1
        for i in range(1,N + 1):
            for j in range(1,M + 1):
                if i - 2 > 0 and j - 1 > 0 and dp[i - 2][j - 1]:
                    dp[i][j] = max(dp[i - 2][j - 1] + 1, dp[i][j])
                if i - 1 > 0 and j - 2 > 0 and dp[i - 1][j - 2]:
                    dp[i][j] = max(dp[i - 1][j - 2] + 1, dp[i][j])
                if i + 2 <= N and j - 1 > 0 and dp[i + 2][j - 1]:
                    dp[i][j] = max(dp[i + 2][j - 1] + 1, dp[i][j])
                if i + 1 <= N and j - 2 > 0 and dp[i + 1][j - 2]:
                    dp[i][j] = max(dp[i + 1][j - 2] + 1, dp[i][j])
                ret = max(ret, dp[i][j])
        return ret
print(solve())