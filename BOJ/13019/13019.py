import sys
input = sys.stdin.readline
A,B = input().strip(), input().strip()

def solve():
    if A == B:
        return 0
    if sorted(A) != sorted(B):
        return -1
    
print(solve())