import sys
input = sys.stdin.readline
A = []
N = int(input())
for i in range(N):
    A.append([input().strip(),i])
A.sort(key=lambda x:x[0])
maxlen, cands = 0, {}
for i in range(N - 1):
    s,t,j = A[i][0],A[i + 1][0],0
    while j < min(len(s),len(t)) and s[j] == t[j]:
        j += 1
    prefix = s[0:j]
    tmp = [A[i],A[i+1]]
    tmp.sort(key=lambda x: x[1])
    maxlen = max(maxlen, j)
    if prefix in cands:
        cands[prefix].append(A[i])
        cands[prefix].append(A[i+1])
    else:
        cands[prefix] = [A[i],A[i+1]]
p = []
for c in cands:
    if len(c) == maxlen:
        cands[c].sort(key=lambda x:x[1])
        x = cands[c][0]
        for i in range(1,len(cands[c])):
            if x[1] != cands[c][i][1]:
                p.append([x,cands[c][i]])
                break
p.sort(key=lambda x:(x[0][1],x[1][1]))
print(p[0][0][0])
print(p[0][1][0])
