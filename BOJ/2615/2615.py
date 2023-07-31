import sys
input = sys.stdin.readline

LEN = 19
A = [[0] * (LEN + 1)]
for _ in range(LEN):
    A.append([0] + list(map(int, input().split())))
A.append([0] * (LEN + 1))
dirs = [[-1, 0], [0, -1], [1, -1], [-1, -1]]
colors = [1, 2]

def check():
    for i in range(1, LEN + 1):
        for j in range(1, LEN + 1):
            if A[i][j] == 0:
                continue
            for d in dirs:
                si, sj = i - d[0], j - d[1]
                if 0 < si <= LEN and 0 < sj <= LEN and A[si][sj] == A[i][j]:
                    continue
                mul, ni, nj = 0, 0, 0
                while mul < 7:
                    ni, nj = i + d[0] * mul, j + d[1] * mul
                    if ni < 1 or nj < 1 or ni > LEN or nj > LEN or A[ni][nj] != A[i][j]:
                        break
                    mul += 1
                if mul == 5:
                    # print(i, j)
                    return [A[i][j], i + d[0] * 4, j + d[1] * 4]
    return []

res = check()
if res:
    print(str(res[0]) + '\n' + str(res[1]) + ' ' + str(res[2]))
else:
    print(0)
