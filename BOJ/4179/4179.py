import sys
from collections import deque
input = sys.stdin.readline
A, ret, flag = [], 0, False
N,M = map(int,input().rstrip().split())
fire_q, q = deque(), deque() # 불, 사람
dir = [[1,0],[-1,0],[0,1],[0,-1]]

for i in range(N):
    A.append(list(input().rstrip()))
    for j in range(M):
        if A[-1][j] == 'J':
            q.append([i,j])
        elif A[-1][j] == 'F':
            fire_q.append([i,j])

def fire_move():
    global fire_q
    cur_len = len(fire_q)
    for _ in range(cur_len):
        x,y = map(int,fire_q.popleft())
        for d in dir:
            nx,ny = x+d[0],y+d[1]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if A[nx][ny] == '.' or A[nx][ny] == 'J':
                A[nx][ny] = 'F'
                fire_q.append([nx,ny])
                
def escape():
    global q, flag
    cur_len = len(q)
    for _ in range(cur_len):
        x,y = map(int,q.popleft())
        if x == 0 or x == N - 1 or y == 0 or y == M - 1: # check edge
            flag = True
            return
        for d in dir:
            nx,ny = x+d[0],y+d[1]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if A[nx][ny] == '.':
                A[nx][ny] = 'J'
                q.append([nx,ny])

while True:
    fire_move()
    escape()
    ret += 1
    if flag or not len(q):
        break

if flag:
    print(ret)
else:
    print("IMPOSSIBLE")
    