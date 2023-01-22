s = input()
N = 0
for i,v in enumerate(s):
    N += int(v) * (2 ** (len(s) - i - 1))
N *= 17
ret = ""
while N:
    ret += str(N % 2)
    N //= 2
print(ret[::-1])