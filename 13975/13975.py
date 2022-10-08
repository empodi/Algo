import sys
import heapq
input = sys.stdin.readline

def solve():
    N, ret = int(input()), 0
    hq = sorted(list(map(int, input().strip().split())))
    while len(hq) > 1:
        a = heapq.heappop(hq)
        b = heapq.heappop(hq)
        ret += (a + b)
        heapq.heappush(hq, a + b)
    return ret

T = int(input())
for _ in range(T):
    print(solve())