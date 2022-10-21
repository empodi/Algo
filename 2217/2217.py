import sys
input = sys.stdin.readline
N = int(input())
A, ret = [], 0
for _ in range(N):
    A.append(int(input().rstrip()))
A.sort()
for i in range(N - 1, -1, -1):
    ret = max(ret, (N - i) * A[i])
print(ret)