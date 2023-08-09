import sys
input = sys.stdin.readline

N = int(input())
answer = 0
stk = []

for _ in range(N):
    elem = int(input())
    if not stk:
        stk.append([elem, 1])
        continue
    if elem < stk[-1][0]:
        stk.append([elem, 1])
        # print(stk, local)
        answer += 1
    else:
        while stk and elem > stk[-1][0]:
            answer += stk[-1][1]
            stk.pop()
        if stk:
            if elem == stk[-1][0]:
                answer += stk[-1][1]
                stk[-1][1] += 1
                if len(stk) > 1:
                    answer += 1
            else:
                stk.append([elem, 1])
                answer += 1
        else:
            stk.append([elem, 1])

print(answer)
