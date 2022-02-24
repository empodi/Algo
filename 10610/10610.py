import sys

def solve(strInput):
    num = int(strInput)
    
    if (num % 30 == 0): return num
    
    val = int("".join(sorted(strInput)[::-1]))
    
    if (val % 30 == 0): return val
    else: return -1

strInput = input()

print(solve(strInput))
