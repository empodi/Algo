import sys
input = sys.stdin.readline
N = int(input())
A = []
a,b = list(map(int,input().strip().split())),list(map(int,input().strip().split()))
for i in range(N):
    A.append([a[i],b[i]])
A.sort(key=lambda x:x[1])
ret = 0
for i in range(N):
    ret += A[i][0] + i * A[i][1]
print(ret)