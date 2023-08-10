LEN = 5
A = [list(input()) for _ in range(LEN)]
visited = [[False for _ in range(LEN)] for _ in range(LEN)]
path = []
answer = 0

def dfs(x, y):
    if x < 0 or y < 0 or x >= LEN or y >= LEN or visited[x][y]:
        return 0
    if [x, y] not in path:
        return 0
    visited[x][y] = True
    return dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y - 1) + dfs(x, y + 1) + 1

def go(start, sCnt, yCnt):
    if yCnt > 3:
        return
    if len(path) == 7:
        if yCnt > sCnt:
            return
        for i in range(LEN):
            for j in range(LEN):
                visited[i][j] = False
        if dfs(path[0][0], path[0][1]) < 7:
            return
        global answer
        answer += 1
        return
    for i in range(start, LEN * LEN):
        path.append([i // LEN, i % LEN])
        if A[i // LEN][i % LEN] == 'S':
            go(i + 1, sCnt + 1, yCnt)
        else:
            go(i + 1, sCnt, yCnt + 1)
        path.pop()

go(0, 0, 0)
print(answer)
