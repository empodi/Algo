import sys
input = sys.stdin.readline
N = int(input())
myset = set()
for _ in range(N):
    a,b = map(str,input().rstrip().split())
    if a == "ChongChong" or b == "ChongChong":
        myset.add(a)
        myset.add(b)
    else:
        if a in myset:
            myset.add(b)
        if b in myset:
            myset.add(a)
print(len(myset))
