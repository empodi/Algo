import sys
input = sys.stdin.readline

N, M = map(int,input().split())
A = list(map(int,input().split()))

def check(mid):
    cnt = 0
    for a in A:
        cnt += (mid // a + 1)
    return cnt >= N

def solve():
    if N <= M: return N
    s, e, minTime = 1, int(2*1e9) * 30, 0
    while s <= e:
        mid = (s + e) //2
        if check(mid):
            minTime = mid
            e = mid - 1
        else:
            s = mid + 1
    cnt, ans = 0, 1
    for a in A:
        cnt += (minTime - 1) // a + 1
    for i in range(M):
        if not minTime % A[i]:
            cnt += 1
            ans = i + 1
        if cnt == N:
            break
    return ans
    
print(solve())