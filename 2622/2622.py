N = int(input())
a =  N // 3 + 1
ret = 0
while True:
    if a >= N - a:
        break
    twoSum = N - a
    x,y = twoSum - a, a
    ret += (y - x + 1) // 2 if (y - x + 1) % 2 == 0 else (y - x + 1) // 2 + 1
    a += 1
if N % 3 == 0:
    ret += 1
print(ret)