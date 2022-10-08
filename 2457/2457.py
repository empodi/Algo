import sys
import heapq
input = sys.stdin.readline
N = int(input())
A, S, E = [], 301, 1131
for _ in range(N):
    a,b,c,d = map(int, input().strip().split())
    A.append([a * 100 + b, c * 100 + d])
A.sort(key=lambda x:(x[0], x[1]))

def solve():
    global N, S, E
    if A[0][0] > S: 
        return 0
    i, lim, ret = 0, S, 1
    while i < N:
        curMax = 0
        while i < N and A[i][0] <= lim:
            curMax = max(curMax, A[i][1])
            i += 1
        if curMax == 0:
            i += 1
        else:
            lim = curMax
            if curMax >= E:
                return ret
            ret += 1
    return 0

print(solve())
