n = int(input())
arr = list(map(int, input().split()))
max_len = 1
curr = 1
for i in range(1, n):
    if arr[i] < arr[i-1]:
        curr += 1
        max_len = max(max_len, curr)
    else:
        curr = 1
print(max_len)
