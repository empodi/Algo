import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().rstrip().split()))
cnt = [0 for _ in range(100001)]
l,r,ret = 0,0,0
while r < N:
    while l < r and cnt[A[r]]:
        cnt[A[l]] -= 1
        l += 1
    cnt[A[r]] += 1
    r += 1
    ret += r - l
print(ret)
    
        