
m, n = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
merged = sorted(a + b)
total = m + n
if total % 2 == 1:
    print(merged[total // 2])
else:
    med = (merged[total // 2 - 1] + merged[total // 2]) / 2
    print(int(med) if med == int(med) else med)
