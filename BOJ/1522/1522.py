import sys
from itertools import groupby
input = sys.stdin.readline
A = ["".join(grp) for num, grp in groupby(input().rstrip())]
print(A)