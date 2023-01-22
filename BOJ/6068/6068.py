import sys
input = sys.stdin.readline
N = int(input().strip())
A=[]
for i in range(N):
    A.append(list(map(int,input().strip().split())))
A.sort(key=lambda x:(x[1],x[0]))

#print(A)
def solve():
    global N
    start = A[-1][1] - A[-1][0]
    for i in range(N-2,-1,-1):
        start = min(start,A[i][1])
        start -= A[i][0]
    return -1 if start < 0 else start
print(solve())
