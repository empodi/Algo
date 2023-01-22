import sys
input = sys.stdin.readline
N = int(input())
fcnt = N // 5
flag = False
while fcnt >= 0:
    if (N - fcnt * 5) % 2 == 0:
        print(fcnt + (N - fcnt * 5) // 2)
        flag = True
        break
    fcnt -= 1
if not flag:
    print(-1)