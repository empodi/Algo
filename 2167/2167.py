import sys
input = sys.stdin.readline
N,M = map(int,input().split())
dp = [[0 for x in range(M + 1)]]
for i in range(N):
    a = list(map(int,input().split()))
    dp.append([0] + a)
for i in range(1, N + 1):
    for j in range(1, M + 1):
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]
T = int(input())
for _ in range(T):
    x,y,p,q = map(int,input().split())
    print(dp[p][q] - dp[p][y - 1] - dp[x - 1][q] + dp[x - 1][y - 1])