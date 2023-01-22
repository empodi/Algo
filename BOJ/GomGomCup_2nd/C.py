import sys
input = sys.stdin.readline
A = list(map(int,input().rstrip().split()))
B = list(map(int,input().rstrip().split()))
ret = 0
for i in range(3):
    people = A.copy()
    food = B.copy()
    cur, idx = 0, i
    for _ in range(3):
        cur += min(people[idx],food[idx])
        nextIdx = (idx + 1) % 3
        food[nextIdx] += max(0,food[idx] - people[idx]) // 3
        idx = nextIdx
    ret = max(ret, cur)
print(ret)