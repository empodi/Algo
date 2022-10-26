import sys
input = sys.stdin.readline
N, k = map(int,input().rstrip().split())
flag = False
while k < 101:
    s = k * (k - 1) // 2
    if N - s < 0:
        break
    if not (N - s) % k:
        flag = True
        for i in range(k):
            print((N - s) // k + i, end=' ')
        print()
        break
    k += 1
    
if not flag:
    print(-1)
      