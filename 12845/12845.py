import sys
input = sys.stdin.readline
N, A = int(input().strip()), list(map(int,input().strip().split()))
print(max(A) * (len(A) - 1) + sum(A) - max(A))
