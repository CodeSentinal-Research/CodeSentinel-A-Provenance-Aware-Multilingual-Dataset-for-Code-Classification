m = int(input())
a = list(map(int, input().split()))
n = int(input())
b = list(map(int, input().split()))
merged = sorted(a + b)
total = m + n
if total % 2 == 0:
    print((merged[total // 2 - 1] + merged[total // 2]) / 2)
else:
    print(merged[total // 2])
