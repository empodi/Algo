import os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

RIPE, NONE_RIPE, BLANK = 1, 0, -1
dirs = [[1,0],[-1,0],[0,1],[0,-1]]

M, N = map(int, input().split())
A = [list(map(int, input().rstrip().split())) for _ in range(N)]

nonRipeCount = 0
q = []

for i in range(N):
    for j in range(M):
        if A[i][j] == NONE_RIPE:
            nonRipeCount += 1
        elif A[i][j] == RIPE:
            q.append([i, j])

ret = 0
while q:
    ret += 1
    temp_q = []
    for x, y in q:
        for d in dirs:
            nx, ny = x + d[0], y + d[1]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if A[nx][ny] == NONE_RIPE:
                nonRipeCount -= 1
                A[nx][ny] = RIPE
                temp_q.append([nx, ny])
    q = temp_q

print(ret - 1 if nonRipeCount == 0 else -1)
