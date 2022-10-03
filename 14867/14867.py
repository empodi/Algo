import sys
from collections import deque

input = sys.stdin.readline
X,Y,a,b = map(int,input().split())

def solve():
    dq = deque()
    st = set()
    dq.append([0,0,0])    
    st.add(str([0,0]))
    while len(dq):
        x,y,cnt = map(int, dq.popleft())
        if x == a and y == b:
            return cnt
        # Fill x
        if x < X:
            nx,ny = X,y
            if str([nx,ny]) not in st:
                st.add(str([nx,ny]))
                dq.append([nx,ny,cnt + 1])
        if y < Y:
            nx,ny = x,Y
            if str([nx,ny]) not in st:
                st.add(str([nx,ny]))
                dq.append([nx,ny, cnt + 1])
        if x:
            nx,ny = 0,y
            if str([nx,ny]) not in st:
                st.add(str([nx,ny]))
                dq.append([nx,ny, cnt + 1])
        if y:
            nx,ny = x,0
            if str([nx,ny]) not in st:
                st.add(str([nx,ny]))
                dq.append([nx,ny, cnt + 1])
        if x < X and y:
            diff = X - x
            nx, ny = min(x + y, X), max(0, y - diff)
            if str([nx,ny]) not in st:
                st.add(str([nx,ny]))
                dq.append([nx,ny, cnt + 1])
        if y < Y and x:
            diff = Y - y
            nx, ny = max(0, x - diff), min(x + y, Y)
            if str([nx,ny]) not in st:
                st.add(str([nx,ny]))
                dq.append([nx,ny, cnt + 1])
    return -1

print(solve())