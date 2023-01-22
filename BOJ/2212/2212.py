import sys
import heapq
input = sys.stdin.readline
N = int(input().rstrip())
K = int(input().rstrip())
A = sorted(list(set(map(int,input().rstrip().split()))))

pq, ret = [], 0
for i in range(1,len(A)):
    heapq.heappush(pq, A[i] - A[i - 1])
for _ in range(len(A) - K):
    ret += pq[0]
    heapq.heappop(pq)
print(ret)
