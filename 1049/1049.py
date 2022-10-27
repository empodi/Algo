import sys
input = sys.stdin.readline
N,M = map(int,input().rstrip().split())
a,b = float("inf"), float("inf")
for _ in range(M):
    x,y = map(int,input().rstrip().split())
    a,b = min(a,x), min(b,y)
A = (N % 6) * b + a * (N // 6) if (N // 6) else a
B = a * ((N // 6) if not (N % 6) else (N // 6) + 1)
print(min(A,B,N*b))