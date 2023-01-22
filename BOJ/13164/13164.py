import sys
input = sys.stdin.readline
N,K = map(int,input().strip().split())
A = list(map(int,input().strip().split()))
for i in range(N-1,0,-1):
    A[i] -= A[i - 1]
A[0]=0
A.sort()
for _ in range(K-1):
    A.pop()
print(sum(A))
