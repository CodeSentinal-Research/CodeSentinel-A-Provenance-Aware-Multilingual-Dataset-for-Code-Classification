n = int(input())
arr = list(map(int, input().split()))
max_zeros = 0
curr = 0
for x in arr:
    if x == 0:
        curr += 1
        max_zeros = max(max_zeros, curr)
    else:
        curr = 0
print(max_zeros)
