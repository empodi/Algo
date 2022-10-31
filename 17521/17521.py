import sys
input = sys.stdin.readline

def solve():
    N, W = map(int,input().rstrip().split())
    A = []
    for _ in range(N):
        A.append(int(input()))
    if N == 1:
        return W
    day, i = [], 1
    while i < N:
        if A[i] > A[i - 1]:
            j = i
            while j < N and A[j] > A[j - 1]:
                j += 1
            day.extend([i,j])
            i = j
        else:
            i += 1
    coin = 0
    for i in range(len(day)):
        if not i % 2:
            coin = W // A[day[i]-1]
            W -= coin * A[day[i]-1]
        else:
            W += coin * A[day[i] - 1]
            coin = 0
    return W    
    
print(solve())