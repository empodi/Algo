N, _sum, cur = int(input()),0,1
while True:
    _sum += cur
    if _sum > N:
        break
    cur += 1
print(cur - 1)