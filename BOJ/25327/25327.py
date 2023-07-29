import sys
input = sys.stdin.readline
N, M = map(int,input().split())
hash = {
    'kor': 0,
    'eng': 1,
    'math': 2,
    'apple': 0,
    'pear': 1,
    'orange': 2,
    'red': 0,
    'blue': 1,
    'green': 2,
    '-': 3,
}
memo = [[[0,0,0,0] for _ in range(4)] for _ in range(4)]
tp = [(),(0,),(1,),(2,),(0,1),(1,2),(0,2),(0,1,2)]
for _ in range(N):
    arr = list(map(lambda x: hash[x], input().split()))
    for e in tp:
        lst = []
        for i in range(3):
            if i in e:
                lst.append(3)
            else:
                lst.append(arr[i])
        memo[lst[0]][lst[1]][lst[2]] += 1

for _ in range(M):
    x, y, z = map(lambda x: hash[x], input().split())
    print(memo[x][y][z])
