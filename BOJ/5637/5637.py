import sys
input = sys.stdin.readline
ret = ''
while True:
    A = list(input().rstrip().split())
    if not len(A):
        continue
    for e in A:
        word = ''
        for c in e:
            if c.isalpha() or c == '-':
                word += c
        if len(word) > len(ret):
            ret = word
    if A[-1] == "E-N-D":
        break
print(ret.lower())