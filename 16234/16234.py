import sys
from collections import deque
input = sys.stdin.readline
N,L,R = map(int,input().split())
A = [list(map(int,input().strip().split())) for _ in range(N)]
dir = [[1,0],[-1,0],[0,1],[0,-1]]
visited = [[False for x in range(N+1)] for _ in range(N+1)]

def BFS(i,j):
    global N,L,R
    ret = False
    path, dq, s = [], deque(), A[i][j]
    dq.append([i,j])
    path.append([i,j])
    visited[i][j] = True
    while len(dq):
        x,y = map(int,dq.popleft())
        for d in dir:
            nx,ny = x+d[0],y+d[1]
            if nx < 0 or ny < 0 or nx >= N or ny >= N or visited[nx][ny]:
                continue
            diff = abs(A[x][y] - A[nx][ny])
            if diff >= L and diff <= R:
                visited[nx][ny] = True
                path.append([nx,ny])
                dq.append([nx,ny])
                s += A[nx][ny]
                ret = True
    for e in path:
        A[e[0]][e[1]] = s // len(path)
    return ret

def checkBFS(x,y):
    for d in dir:
        nx,ny = x+d[0],y+d[1]
        if nx < 0 or ny < 0 or nx >= N or ny >= N:
            continue
        diff = abs(A[x][y] - A[nx][ny])
        if diff >= L and diff <= R:
            return True
    return False

ans = 0
while True: 
    flag = False
    for i in range(N):
        for j in range(N):
            if not visited[i][j] and checkBFS(i,j):
                flag |= BFS(i,j)
    if not flag:
        break
    for i in range(N):
        for j in range(N):
            visited[i][j] = False
    ans += 1
print(ans)
    