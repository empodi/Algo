import sys
input = sys.stdin.readline
N, A = int(input()), []
for _ in range(N):
    A.append(int(input()))
A.sort()
for _ in range(5):
    A.append(-1)

maxSeq = 0 
for i in range(N):
    tmp, cnt = set([x for x in range(A[i],A[i]+5)]), 0
    for j in range(i,i+5):
        if A[j] in tmp:
            cnt += 1
    maxSeq = max(maxSeq,cnt)
print(5 - maxSeq)
    
