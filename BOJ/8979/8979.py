import sys
input = sys.stdin.readline
N, K = map(int,input().rstrip().split())
A = []
for _ in range(N):
    A.append(list(map(int,input().rstrip().split())))
A.sort(key=lambda x:(-x[1],-x[2],-x[3]))
rank = 1
for i in range(N):
    if i and A[i - 1][1:4] != A[i][1:4]:
        rank = max(i + 1, rank + 1)
    if A[i][0] == K:
        print(rank)
        break
