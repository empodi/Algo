import sys
from collections import deque
input = sys.stdin.readline

MAX, BLANK, BLOCK, VIRUS, DONE = 987654321, 0, 1, 2, 3
N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
B = [[0 for _ in range(N)] for _ in range(N)]
dirs = [[1,0],[-1,0],[0,1],[0,-1]]
answer, totalBlank = MAX, 0

viruses = []

for i in range(N):
    for j in range(N):
        if A[i][j] == VIRUS:
            viruses.append([i, j])
        if A[i][j] == BLANK:
            totalBlank += 1

def bfs() -> int:
    q = deque()
    blankCnt, cnt = 0, 0
    for r in range(N):
        for c in range(N):
            B[r][c] = A[r][c]
            if B[r][c] == BLANK:
                blankCnt += 1
    for e in cur:
        q.append([viruses[e][0], viruses[e][1]])
        B[viruses[e][0]][viruses[e][1]] = DONE
    while q:
        temp_q = deque()
        for x, y in q:
            for d in dirs:
                nx, ny = x + d[0], y + d[1]
                if nx < 0 or ny < 0 or nx >= N or ny >= N:
                    continue
                if B[nx][ny] == DONE or A[nx][ny] == BLOCK:
                    continue
                if B[nx][ny] == BLANK:
                    blankCnt -= 1
                B[nx][ny] = DONE
                temp_q.append([nx, ny])
        q = temp_q
        if q:
            cnt += 1
        if not blankCnt:
            break

    return MAX if blankCnt > 0 else cnt

cur = []
def go(idx):
    if len(cur) == M:
        global answer
        answer = min(answer, bfs())
        return
    for i in range(idx, len(viruses)):
        cur.append(i)
        go(i + 1)
        cur.pop()

if totalBlank == 0:
    print(0)
else:
    go(0)
    print(answer if answer != MAX else -1)