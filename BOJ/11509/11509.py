import sys
input = sys.stdin.readline
N = int(input().strip())
A = list(map(int,input().strip().split()))
M = int(1e6)
check = [0 for _ in range(M + 1)]
for e in A:
    if e < M and check[e + 1]:
        check[e + 1] -= 1
    check[e] += 1
print(sum(check))
