import sys
input = sys.stdin.readline
N = int(input().strip())
A = list(map(int,input().strip().split()))
B,C = A.copy(), A.copy()
for i in range(1,N):
    B[i] += B[i - 1]
for i in range(N-2,-1,-1):
    C[i] += C[i + 1]
ans = 0
for i in range(N-2,0,-1):
    ans = max(ans, B[N-2]-A[i]+B[i -1], C[1]-A[i]+C[i + 1], B[i]-A[0]+C[i]-A[-1])
print(ans)