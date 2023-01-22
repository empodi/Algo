import sys
input = sys.stdin.readline
a,b = map(int,input().strip().split())

# set digits array - 이진수 자리 수 단위로 1이 나타나는 횟수의 누적합
digits = [0 for i in range(60)]
digits[1], tmpSum = 1, 1
for i in range(2,60):
    digits[i] = 2 ** (i - 1) + tmpSum
    tmpSum += digits[i]
    digits[i] += digits[i - 1]

def decToBin(n): # returns string
    if n == 0:
        return "0"
    ret = []
    while n:
        ret.append(n % 2)
        n //= 2
    ret.reverse()
    return "".join(map(str,ret))

def calOnes(s):
    if s == "0" or s == "1":
        return int(s)
    A = list(map(int,s))
    if sum(A) == len(A):
        return digits[len(s)] - digits[len(s) - 1]
    if sum(A) == 1:
        return digits[len(s ) - 1] + 1
    ret, cnt = digits[len(s) - 1], 1
    for i in range(1,len(s)):
        if s[i] == '1':
            cnt += 1
            if i == len(s) - 1:
                ret += cnt
            else:
                ret += cnt * digits[len(s)-i-1] + 1
    return ret + 1
x, y = calOnes(decToBin(b)), calOnes(decToBin(a - 1))
print(x - y)
