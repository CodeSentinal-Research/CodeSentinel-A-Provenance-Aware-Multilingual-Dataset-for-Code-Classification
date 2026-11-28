n = int(input())
arr = list(map(int, input().split()))
max_sum = float('-inf')
curr = 0
for x in arr:
    curr = max(x, curr + x)
    max_sum = max(max_sum, curr)
print(max_sum)
