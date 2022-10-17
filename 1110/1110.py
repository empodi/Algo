import sys
input = sys.stdin.readline
s = input().strip()
s = s if len(s) == 2 else '0' + s
start, ret = s, 1
while True:
    _sum = str(int(s[0]) + int(s[1])) # _sum is string
    s = s[-1] + _sum[-1]
    if s == start:
        break
    ret += 1
print(ret)
