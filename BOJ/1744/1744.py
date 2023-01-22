import sys
import heapq
input = sys.stdin.readline
N, zero, total, s = int(input().strip()), 0, 0, 0
pos, neg = [], []
for _ in range(N):
    n = int(input().strip())
    total += n
    if n > 0: 
        heapq.heappush(pos,-n)
    elif n < 0:
        heapq.heappush(neg, n)
    else:
        zero += 1
while len(pos) > 1:
    a,b = -heapq.heappop(pos), -heapq.heappop(pos)
    if a == 1 or b == 1:
        heapq.heappush(pos,-a)
        heapq.heappush(pos,-b)
        break
    else:
        s += a * b
while len(pos) > 0:
    s += -heapq.heappop(pos)
while len(neg) > 1:
    s += heapq.heappop(neg) * heapq.heappop(neg)
while zero > 0 and len(neg) > 0:
    heapq.heappop(neg)
    zero -= 1
while len(neg) > 0:
    s += heapq.heappop(neg)
print(max(total,s))
