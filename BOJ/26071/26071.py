import sys
input = sys.stdin.readline

MAX = 987654321
N = int(input())
A = [list(input().rstrip()) for _ in range(N)]

sx, sy, ex, ey = MAX, MAX, 0, 0

for i in range(N):
    for j in range(N):
        if A[i][j] == 'G':
            sx = min(sx, i)
            sy = min(sy, j)
            ex = max(ex, i)
            ey = max(ey, j)
            
if sx == ex and sy == ey:
    print(0)
elif sx == ex:
    print(min(N - 1 - sy, ey))
elif sy == ey:
    print(min(ex, N - 1 - sx))
else:
    print(min(ex, N - 1 - sx) + min(N - 1 - sy, ey))