import sys
from collections import deque
input = sys.stdin.readline
N, M = map(int,input().rstrip().split())
A = []
for _ in range(N):
    A.append(list(map(int,input().rstrip().split())))
dist = [[float("inf") for _ in range(M)] for r in range(N)]
dir = [[1,-1],[1,0],[1,1],[0,-1],[0,1],[-1,-1],[-1,0],[-1,1]]
ret = 0

for i in range(N):
    for j in range(M):
        if A[i][j]:
            visited = [[False for _ in range(M)] for r in range(N)]
            visited[i][j] = True
            dq = deque()
            dq.append([i,j,0])
            while len(dq):
                x,y,c = map(int,dq.popleft())
                c += 1
                for d in dir:
                    nx, ny = x + d[0], y + d[1]
                    if nx < 0 or ny < 0 or nx >= N or ny >= M or A[nx][ny] or visited[nx][ny]:
                        continue
                    if c < dist[nx][ny]:
                        dist[nx][ny] = c
                        dq.append([nx,ny,c])

for i in range(N):
    for j in range(M):
        if dist[i][j] < float("inf"):
            ret = max(ret,dist[i][j])
print(ret)
                