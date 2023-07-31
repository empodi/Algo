import sys
input = sys.stdin.readline

left, right = [], []
for c in input().rstrip():
    left.append(c)
N = int(input())
for _ in range(N):
    cmd = input().rstrip()
    if cmd[0] == 'P':
        a = cmd.split()[-1]
        left.append(a)
    elif cmd[0] == 'L':
        if left:
            right.append(left[-1])
            left.pop()
    elif cmd[0] == 'D':
        if right:
            left.append(right[-1])
            right.pop()
    elif cmd[0] == 'B':
        if left:
            left.pop()
print("".join(left) + "".join(right[::-1]))
