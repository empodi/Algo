import sys
from collections import deque
input = sys.stdin.readline

N,K = map(int, input().split())
s = input()
dq = deque()
for i in range(N):
    while len(dq) and len(dq) + N - i > N - K and s[i] > dq[-1]:
        dq.pop()
    dq.append(s[i])
while len(dq) > N - K:
    dq.pop()
print("".join(dq))
