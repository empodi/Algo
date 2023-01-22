import sys
from collections import deque
input = sys.stdin.readline

height, width = map(int,input().split())
A = [list(map(lambda x: 0 if x == '.' else int(x),input().strip())) for _ in range(height)]
visited = [[False for x in range(width)] for y in range(height)]
dir = [[1,1],[1,0],[1,-1],[0,1],[0,-1],[-1,1],[-1,0],[-1,-1]]
ans = 0
q = deque()

# first Q
# 모래성과 인접한 물 부분으로 Q 초기화
for i in range(height):
    for j in range(width):
        if not A[i][j]:
            visited[i][j] = True
            for d in dir:
                ni, nj = i + d[0], j + d[1]
                if ni < 0 or nj < 0 or ni >= height or nj >= width:
                    continue
                if A[ni][nj]:
                    q.append([i,j])
                    break

while True:
    tempQ = deque()
    while len(q):
        x,y = q.popleft()
        for d in dir:
            nx, ny = x + d[0], y + d[1]
            if nx < 0 or ny < 0 or nx >= height or ny >= width or visited[nx][ny]:
                continue
            if A[nx][ny] > 0:
                visited[x][y] = True
                A[nx][ny] -= 1
                if not A[nx][ny]:
                    tempQ.append([nx,ny])
    if not len(tempQ):
        break;
    ans += 1
    q,tempQ = tempQ,q
    
print(ans)
