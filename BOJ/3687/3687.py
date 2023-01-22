import sys
input = sys.stdin.readline
dic = { 2:['1'], 3:['7'], 4:['4'], 5:['2','3','5'], 6:['0','6','9'], 7:['8'] }

min_str = ['' for _ in range(101)]
max_str = ['' for _ in range(101)]

def get_min(a:str, b:str) -> str: 
    if len(a) == len(b):
        for i in range(len(a)):
            if a[i] == b[i]: continue
            if a[i] < b[i]: return a
            else: return b
    if len(a) < len(b):
        return a
    return b

# set min
for i in range(2,8):
    min_str[i] = dic[i][0] if i != 6 else dic[i][1]
for i in range(8,101):
    res = '9'*100
    for j in range(2,8):
        if i - j < 2: continue
        a = min_str[i - j] + dic[j][0]
        res = get_min(res,a)
    min_str[i] = res
    
# set max
max_str[2] = dic[2][-1]
max_str[3] = dic[3][-1]
for i in range(4,101):
    max_str[i] = max_str[i - 2] + '1'

T = int(input())
for _ in range(T):
    n = int(input())
    print(min_str[n],max_str[n])