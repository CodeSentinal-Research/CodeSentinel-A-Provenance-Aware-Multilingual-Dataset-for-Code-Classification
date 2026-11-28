n = int(input())
arr = list(map(int, input().split()))
s = set(arr)
max_len = 0
for x in s:
    if x - 1 not in s:
        curr = x
        length = 1
        while curr + 1 in s:
            curr += 1
            length += 1
        max_len = max(max_len, length)
print(max_len)
