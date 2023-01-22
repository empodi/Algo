import sys
import heapq
input = sys.stdin.readline
N = int(input())
A = [list(map(int,input().strip().split())) for _ in range(N)]
A.sort()
pq, ans = [], 1
heapq.heappush(pq, A[0][1])
for i in range(1, N):
    while len(pq) and pq[0] <= A[i][0]:
        heapq.heappop(pq)
    heapq.heappush(pq, A[i][1])
    ans = max(ans, len(pq))
print(ans)