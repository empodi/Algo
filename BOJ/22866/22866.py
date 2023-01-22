import sys
from collections import deque
input = sys.stdin.readline
N, A = int(input()), list(map(int,input().rstrip().split()))
close, cnt = [float("inf") for _ in range(N)], [0 for _ in range(N)]
stk = deque() # 스택에 인덱스(건물 번호)를 저장

for i in range(N):
    while len(stk) and A[stk[-1]] <= A[i]:
        stk.pop()
    cnt[i] += len(stk)
    if len(stk):
        close[i] = stk[-1]
    stk.append(i)
    
stk.clear()
for i in range(N-1,-1,-1):
    while len(stk) and A[stk[-1]] <= A[i]:
        stk.pop()
    cnt[i] += len(stk)
    if len(stk) and (abs(i - stk[-1]) < abs(i - close[i])):
        close[i] = stk[-1]
    stk.append(i)

for i in range(N):
    print(cnt[i],close[i]+1) if cnt[i] else print(0)
