import sys
input = sys.stdin.readline
N = int(input().rstrip())
A = list(map(int,input().rstrip().split()))
B,C = map(int,input().rstrip().split())
print(N + sum(((e - B) // C + 1 if (e - B) % C else (e - B) // C) if B < e else 0 for e in A))