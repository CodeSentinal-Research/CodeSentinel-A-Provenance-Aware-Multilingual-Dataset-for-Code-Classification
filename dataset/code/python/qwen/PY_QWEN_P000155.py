n = int(input())
arr = list(map(int, input().split()))
max_ones = 0
curr = 0
for x in arr:
    if x == 1:
        curr += 1
        max_ones = max(max_ones, curr)
    else:
        curr = 0
print(max_ones)
