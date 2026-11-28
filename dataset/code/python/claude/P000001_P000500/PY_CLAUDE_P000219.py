
n, k = map(int, input().split())
a = list(map(int, input().split()))
p = 1
for x in a[-k:]: p *= x
print(p)
