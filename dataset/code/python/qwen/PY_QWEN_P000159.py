n = int(input())
arr = list(map(int, input().split()))
min_sum = float('inf')
curr = 0
for x in arr:
    curr = min(x, curr + x)
    min_sum = min(min_sum, curr)
print(min_sum)
