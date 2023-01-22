import sys
input = sys.stdin.readline
N, ret = int(input()), 0

def cal(a,b,c):
    if a == b and b == c:
        return 10000 + a * 1000
    elif a == b or a == c:
        return 1000 + a * 100
    elif b == c:
        return 1000 + b * 100
    else:
        return max(a,b,c) * 100
    return 0

for _ in range(N):
    a,b,c = map(int,input().rstrip().split())
    ret = max(ret,cal(a,b,c))
print(ret)