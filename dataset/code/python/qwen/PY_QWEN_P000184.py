n, k = map(int, input().split())
arr = list(map(int, input().split()))
prefix = {0: -1}
curr = 0
max_len = 0
for i, x in enumerate(arr):
    curr += x
    if curr - k in prefix:
        max_len = max(max_len, i - prefix[curr - k])
    if curr not in prefix:
        prefix[curr] = i
print(max_len)
