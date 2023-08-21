import sys
input = sys.stdin.readline

N = int(input())
st = set()
pset = set()

def check(num) -> bool:
    if num <= 1:
        return False
    for i in range(2, num):
        if i * i > num:
            break
        if num % i == 0:
            return False
    return True

def go(num):
    if num in st:
        return
    st.add(num)
    if num or num in pset:
        if not check(num):
            return
        else:
            pset.add(num)
            if len(str(num)) == N:
                print(num)
                return
    for i in range(10):
        if i == 2 or i % 2:
            go(num * 10 + i)

go(0)