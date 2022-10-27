import sys
from itertools import groupby
input = sys.stdin.readline
print(len(["".join(grp) for num, grp in groupby(input().rstrip())])//2)