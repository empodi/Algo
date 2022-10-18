import sys
input = sys.stdin.readline
N = int(input().strip())
A = [0]
for _ in range(N):
    A.append(int(input().strip()))

done = [False for _ in range(N+1)]
searching = [False for _ in range(N+1)]
ans, tmp, target = [], [], 0

def dfs(cur):
    global target
    if cur == target:
        return True
    if done[cur] or searching[cur]:
        return False
    tmp.append(cur)
    searching[cur] = True
    return False | dfs(A[cur])
    
for i in range(1,N+1):
    if not done[i]:
        tmp, target = [i], i
        if dfs(A[i]):
            ans.extend(tmp)
            for e in tmp:
                done[e] = True
        searching = [False for _ in range(N+1)]
                
ans = sorted(list(set(ans)))
print(len(ans))
for e in ans:
    print(e)
