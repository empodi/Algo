from collections import deque
import sys
input = sys.stdin.readline

T = int(input().rstrip())
MAX = 10000

for t in range(T):
    A, B = map(int, input().rstrip().split())
    visited = [False for _ in range(MAX)]
    q = deque([[A, '']])

    while q:
        num, st = q.popleft()
        if num == B:
            print(st)
            break

        # D
        newNum = (num * 2) % MAX
        if not visited[newNum]:
            visited[newNum] = True
            q.append([newNum, st + 'D'])

        # S
        newNum = 9999 if num == 0 else num - 1
        if not visited[newNum]:
            visited[newNum] = True
            q.append([newNum, st + 'S'])

        # L
        left = num // 1000
        right = num - left * 1000
        newNum = right * 10 + left
        if not visited[newNum]:
            visited[newNum] = True
            q.append([newNum, st + 'L'])

        # R
        left, right = num % 10, num // 10
        newNum = left * 1000 + right
        if not visited[newNum]:
            visited[newNum] = True
            q.append([newNum, st + 'R'])
