import sys
input = sys.stdin.readline
N = int(input().rstrip())
S, A, i = input().strip(), [], 0
while i < N:
    j = i + 1
    while j < N and S[i] == S[j]:
        j += 1
    A.append(j - i)
    i = j
# A 길이가 홀수
if len(A) % 2:
    x,y=0,0
    for i,v in enumerate(A):
        if i % 2: 
            x += A[i]
        else:
            y += A[i]
    print(min(x, y - max(A[0],A[-1])))
else:
    x,y=0,0
    for i,v in enumerate(A):
        if i == 0 or i == len(A) - 1:
            continue
        if i % 2: 
            x += A[i]
        else:
            y += A[i]
    print(min(x,y))