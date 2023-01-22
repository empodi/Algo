import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
A = []
for _ in range(N):
    A.append(list(map(int,input().rstrip().split())))
A.sort()
l_stk, r_stk, ret = [], [], 0
for i in range(N):
    if not len(l_stk):
        l_stk.append(A[i])
    elif A[i][-1] >= l_stk[-1][-1]:
        l_stk.append(A[i])
for i in range(N - 1,-1,-1):
    if not len(r_stk):
        r_stk.append(A[i])
    elif A[i][-1] > r_stk[-1][-1]:
        r_stk.append(A[i])
        
if len(l_stk) > 1:
    for i in range(len(l_stk) - 1):
        ret += (l_stk[i + 1][0] - l_stk[i][0]) * l_stk[i][1]
ret += l_stk[-1][1]
if len(r_stk) > 1:
    for i in range(len(r_stk) - 1):
        ret += (r_stk[i][0] - r_stk[i + 1][0]) * r_stk[i][1]
ret += r_stk[-1][1]
if l_stk[-1] == r_stk[-1]:
    ret -= l_stk[-1][1]
print(ret)
