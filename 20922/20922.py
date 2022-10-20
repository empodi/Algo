import sys
input = sys.stdin.readline
N,K = map(int,input().rstrip().split())
A = list(map(int,input().rstrip().split()))
count = [0 for _ in range(100001)]
s,e,ret = 0,0,0
while e < N:
    while s < e and count[A[e]] == K:
        count[A[s]] -= 1
        s += 1
    count[A[e]] += 1
    ret = max(ret, e-s+1)
    e += 1
print(ret)