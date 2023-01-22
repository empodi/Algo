import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().strip().split()))

ans = 0
while True:
    cnt = 0
    for i in range(N):
        if A[i] % 2:
            A[i] -= 1
            cnt += 1
    ans += cnt
    cnt = 0
    for i in range(N):
        if A[i]:
            A[i] //= 2
            cnt += 1
    if cnt: 
        ans += 1
    if sum(A) == 0:
        break
print(ans)
