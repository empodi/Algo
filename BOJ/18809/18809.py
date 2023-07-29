from collections import deque

LAKE, BLOCK, OK, RED, GREEN, FLOWER = 0, 1, 2, 3, 4, 5
N, M, G, R = map(int, input().split())
A = [list(map(int,input().split())) for _ in range(N)]
grounds = []
dirs = [[1,0],[-1,0],[0,1],[0,-1]]
for i in range(N):
    for j in range(M):
        if A[i][j] == OK:
            grounds.append([i, j])
# print(grounds)

global greens, reds, answer
greens, reds = [], []
answer = 0

def cal() -> int:
    ret = 0
    B = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            B[i][j] = A[i][j]
    gq, rq = deque(), deque()
    for i in greens:
        gq.append(grounds[i])
        B[grounds[i][0]][grounds[i][1]] = LAKE
    for i in reds:
        rq.append(grounds[i])
        B[grounds[i][0]][grounds[i][1]] = LAKE
    while gq and rq:
        tmp_g, tmp_r = deque(), deque()
        while gq:
            cur = gq[0]
            gq.popleft()
            if B[cur[0]][cur[1]] == FLOWER:
                continue
            for d in dirs:
                nx, ny = cur[0] + d[0], cur[1] + d[1]
                if nx < 0 or ny < 0 or nx >= N or ny >= M:
                    continue
                if B[nx][ny] == LAKE or B[nx][ny] == GREEN or B[nx][ny] == RED or B[nx][ny] == FLOWER:
                    continue
                B[nx][ny] = GREEN
                tmp_g.append([nx, ny])
        while rq:
            cur = rq[0]
            rq.popleft()
            for d in dirs:
                nx, ny = cur[0] + d[0], cur[1] + d[1]
                if nx < 0 or ny < 0 or nx >= N or ny >= M:
                    continue
                if B[nx][ny] == GREEN:
                    ret += 1
                    B[nx][ny] = FLOWER
                    continue
                if B[nx][ny] == LAKE or B[nx][ny] == GREEN or B[nx][ny] == RED or B[nx][ny] == FLOWER:
                    continue
                B[nx][ny] = LAKE
                tmp_r.append([nx, ny])
        for e in tmp_g:
            if B[e[0]][e[1]] == FLOWER:
                continue
            B[e[0]][e[1]] = LAKE
        gq, rq = tmp_g, tmp_r
    return ret

def go_r(idx):
    global reds
    if len(reds) == R:
        # print(greens, reds)
        global answer
        answer = max(answer, cal())
        return
    for i in range(idx, len(grounds)):
        if i in greens: continue
        reds.append(i)
        go_r(i + 1)
        reds = reds[:-1]

def go_g(idx):
    global greens
    if len(greens) == G:
        # print(greens)
        go_r(0)
        return
    for i in range(idx, len(grounds)):
        greens.append(i)
        go_g(i + 1)
        greens = greens[:-1]

go_g(0)

print(answer)