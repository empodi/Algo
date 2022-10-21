import sys
from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N = int(input().rstrip())
graph = [[] for _ in range(N + 1)]
for _ in range(N):
    x,y = map(int,input().rstrip().split())
    graph[x].append(y)
    graph[y].append(x)

ans = [0 for _ in range(N + 1)]
cycle = [False for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]
start = 0 
    
def dfs_cycle(cur, dist): # check cycle
    global start
    if cur == start:
        if dist > 2:
            return True
        elif dist > 1:
            return False
        # cur == start 이고 dist == 0 이면 계속 진행
    visited[cur] = True
    for e in graph[cur]:
        if not visited[e] or e == start:
            if dfs_cycle(e, dist + 1):
                return True
    return False

def dfs_dist(cur, dist):
    if dist and (cycle[cur] or ans[cur]):
        return
    ans[cur] = dist
    for e in graph[cur]:
        dfs_dist(e, dist + 1)

for i in range(1,N+1):
    start= i
    visited = [False for _ in range(N + 1)]
    if dfs_cycle(i,0):
        cycle[i] = True

for i in range(1,N+1):
    if cycle[i]:
        dfs_dist(i,0)
for i in range(1,N+1):
    print(ans[i],end=' ')
print()
