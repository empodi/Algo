from collections import deque
import sys
input = sys.stdin.readline

BLOCK, EAST, WEST, SOUTH, NORTH, MAX = 1, 1, 2, 3, 4, 987654321
N, M = map(int, input().split())
A = [0 * (M + 1)]
for _ in range(N):
    A.append([0] + list(map(int, input().split())))
sx, sy, sd = map(int, input().split())
ex, ey, ed = map(int, input().split())
dirs = [[0,0],[0,1],[0,-1],[1,0],[-1,0]]
memo = [[[MAX for _ in range(5)] for _ in range(M + 1)] for _ in range(N + 1)]

def calCost(d1, d2):
    if (d1 == EAST and d2 == WEST) or (d1 == WEST and d2 == EAST):
        return 2
    if (d1 == NORTH and d2 == SOUTH) or (d1 == SOUTH and d2 == NORTH):
        return 2
    return 1

q = deque()
q.append([sx, sy, sd, 0])
memo[sx][sy][sd] = 0

while q:
    cx, cy, cd, curCost = q.popleft()
    if curCost < memo[cx][cy][cd]:
        continue
    # change direction
    for d in range(1, 5):
        nxtCost = curCost + calCost(d, cd)
        if nxtCost >= memo[cx][cy][d] or d == cd:
            continue
        memo[cx][cy][d] = nxtCost
        q.append([cx, cy, d, nxtCost])
    # move
    for k in range(1, 4):
        nx, ny, nxtCost = cx + dirs[cd][0] * k, cy + dirs[cd][1] * k, curCost + 1
        if nx < 1 or ny < 1 or nx > N or ny > M or nxtCost >= memo[nx][ny][cd]:
            continue
        if A[nx][ny] == BLOCK:
            break
        memo[nx][ny][cd] = nxtCost
        q.append([nx, ny, cd, nxtCost])

print(memo[ex][ey][ed])