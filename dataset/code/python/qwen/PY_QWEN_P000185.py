n = int(input())
arr = list(map(int, input().split()))
prefix = {0: -1}
curr = 0
max_len = 0
for i, x in enumerate(arr):
    curr += 1 if x == 1 else -1
    if curr in prefix:
        max_len = max(max_len, i - prefix[curr])
    else:
        prefix[curr] = i
print(max_len)
