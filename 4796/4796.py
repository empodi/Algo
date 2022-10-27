import sys
input = sys.stdin.readline
n = 1
while True:
    L,P,V = map(int,input().rstrip().split())
    if not (L+P+V):
        break
    print("Case %d: %d" % (n, (V // P) * L + min(L, V % P)))
    n += 1