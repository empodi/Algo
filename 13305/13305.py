import sys
sys = sys.stdin.readline
N = int(input())
dist = list(map(int,input().strip().split()))
price = list(map(int,input().strip().split()))
minPrice, ans = price[0], price[0] * dist[0]
for i in range(1,N-1):
    minPrice = min(minPrice, price[i])
    ans += dist[i] * minPrice
print(ans)