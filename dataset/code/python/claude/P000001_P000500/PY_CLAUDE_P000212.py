
n, k = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n):
    if a[i] == 0 and (i == 0 or a[i-1] == 0) and (i == n-1 or a[i+1] == 0):
        a[i] = 1; k -= 1
print('true' if k <= 0 else 'false')
