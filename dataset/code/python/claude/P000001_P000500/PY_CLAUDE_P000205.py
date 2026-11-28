
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
merged = sorted(a + b)
med = (merged[n-1] + merged[n]) / 2
print(int(med) if med == int(med) else med)
