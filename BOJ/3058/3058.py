import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
    A = list(filter(lambda x: x % 2 == 0,list(map(int,input().rstrip().split()))))
    print(sum(A),min(A))