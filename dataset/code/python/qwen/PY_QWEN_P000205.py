n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
merged = sorted(a + b)
if n * 2 % 2 == 0:
    print((merged[n - 1] + merged[n]) / 2)
else:
    print(merged[n])
