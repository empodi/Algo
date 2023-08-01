import sys
input = sys.stdin.readline

BLANK, BLOCK, SWORD, MAX = 0, 1, 2, 987654321
dirs = [[1,0],[-1,0],[0,1],[0,-1]]

N, M, T = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

def bfs(): # without sword
    visited = [[[False, False] for _ in range(M)] for _ in range(N)]
    q = [[0,0,0,0]] # r, c, time, sword
    visited[0][0][0] = True
    while q:
        cur = q[0]
        q = q[1:]
        if cur[0] == N - 1 and cur[1] == M - 1:
            return cur[2]
        for d in dirs:
            nx, ny = cur[0] + d[0], cur[1] + d[1]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if cur[3] == 1: # has sword
                if visited[nx][ny][1]:
                    continue
                visited[nx][ny][1] = True
                q.append([nx, ny, cur[2] + 1, 1])
            else:
                if visited[nx][ny][0] or A[nx][ny] == BLOCK:
                    continue
                visited[nx][ny][0] = True
                if A[nx][ny] == SWORD:
                    q.append([nx, ny, cur[2] + 1, 1])
                else:
                    q.append([nx, ny, cur[2] + 1, 0])
    return MAX

res = bfs()
print(res if res <= T else "Fail")
