import sys
input = sys.stdin.readline
N,C = map(int,input().split())
A=[]
for _ in range(N):
    n = int(input())
    A.append(n)
A.sort()

def check(mid):
    prev, cnt = A[0], 1
    for i in range(1,N):
        if A[i] - prev >= mid:
            cnt += 1
            prev = A[i]
    return cnt >= C

s, e, ans = 0, int(1e9), 1
while s <= e:
    mid = (s + e) // 2
    if check(mid):
        ans = mid
        s = mid + 1
    else:
        e = mid - 1
print(ans)
