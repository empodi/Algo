import sys
import heapq
from collections import deque
input = sys.stdin.readline
MAX = 4321
N,M,S,D = 0,0,0,0
graph = []
dist = []
prev = []

def dijkstra():
    global S,D,MAX,dist,prev
    dist = [MAX for _ in range(N + 1)]
    pq = []
    heapq.heappush(pq, [0,S])
    while len(pq):
        cost, cur = pq[0][0], pq[0][1]
        heapq.heappop(pq)
        if dist[cur] < cost:
            continue
        for e in graph[cur]:
            nxt, nxtCost = e[0], e[1]
            if nxt < 0:
                continue
            if cost + nxtCost < dist[nxt]:
                dist[nxt] = cost + nxtCost
                heapq.heappush(pq, [dist[nxt],nxt])
                prev[nxt].clear()
                prev[nxt].append(cur)
            elif cost + nxtCost == dist[nxt]:
                prev[nxt].append(cur)

def bfs_backtrack():
    global N, S, D
    visited = [False for _ in range(N + 1)]
    visited[D] = True
    dq = deque()
    dq.append(D)
    while len(dq):
        x = dq.popleft()
        for e in prev[x]:
            for elem in graph[e]:
                if elem[0] == x:
                    elem[0] = -1
            if visited[e]:
                continue
            if e != S:
                visited[e] = True
                dq.append(e)
    
def solve():
    global N,M,S,D,MAX,graph,dist,prev
    graph = []
    S, D = map(int, input().split())
    graph = [[] for _ in range(N + 1)]
    prev = [[] for _ in range(N + 1)]
    for _ in range(M):
        x,y,c = map(int, input().split())
        graph[x].append([y,c])
    dijkstra()
    bfs_backtrack()
    dijkstra()
    if dist[D] == MAX:
        return -1
    else:
        return dist[D]

while True:
    N, M = map(int, input().split())
    if max(N,M) == 0:
        break
    print(solve())