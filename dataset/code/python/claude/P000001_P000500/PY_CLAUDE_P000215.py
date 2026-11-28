
n, k = map(int, input().split())
a = list(map(float, input().split()))
win = sum(a[:k])
best = win
for i in range(k, n):
    win += a[i] - a[i-k]
    best = max(best, win)
print(f'{best/k:.5f}')
