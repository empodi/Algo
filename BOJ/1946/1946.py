import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, cnt = int(input()), 0
    A = [list(map(int, input().split())) for _ in range(N)]
    A.sort()
    high_rank = A[0][1]
    for i in range(1,N):
        if A[i][1] > high_rank:
            cnt += 1
        high_rank = min(high_rank, A[i][1])
    print(N - cnt)
