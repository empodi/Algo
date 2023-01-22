import sys
input = sys.stdin.readline
N = input() # not used
print(list(map(int,input().rstrip().split())).count(int(input())))