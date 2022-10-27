import sys
input = sys.stdin.readline
A,B = map(int,input().rstrip().split())
N = int(input().rstrip())
L = [abs(A-B)]
for _ in range(N):
    L.append(1 + abs(B - int(input().rstrip())))
print(min(L))