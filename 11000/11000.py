import sys
import heapq
input = sys.stdin.readline

N = int(input())
A = []
for _ in range(N):
    A.append(list(map(int,input().split())))
A.sort()

ret, hq = 0,[]
for e in A:
    while len(hq) and hq[0][0] <= e[0]:
        heapq.heappop(hq)
    heapq.heappush(hq, [e[1],e[0]])
    ret = max(ret, len(hq))
print(ret)
