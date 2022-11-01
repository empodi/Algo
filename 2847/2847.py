N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))
ret, cur = 0, A[-1] - 1
for i in range(N - 2,-1,-1):
    if A[i] > cur:
        ret += (A[i] - cur)
    cur = min(cur - 1,A[i] - 1)
print(ret)
