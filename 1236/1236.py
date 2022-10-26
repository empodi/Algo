import sys
N,M = map(int,input().rstrip().split())
A, p, q = [], 0, 0
for _ in range(N):
    A.append(list(input().strip()))
for i in range(N):
    if 'X' not in A[i]:
        p += 1
for j in range(M):
    flag = False
    for i in range(N):
        if A[i][j] == 'X':
            flag = True
            break
    if not flag:
        q += 1
print(max(p,q))