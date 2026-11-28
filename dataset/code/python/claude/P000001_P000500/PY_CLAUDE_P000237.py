
r, c, k = map(int, input().split())
for _ in range(r):
    row = list(map(int, input().split()))
    k2 = k % c
    print(*(row[k2:]+row[:k2]))
