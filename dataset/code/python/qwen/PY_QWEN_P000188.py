n, target = map(int, input().split())
arr = list(map(int, input().split()))
curr = 0
start = 0
for end in range(n):
    curr += arr[end]
    while curr > target and start <= end:
        curr -= arr[start]
        start += 1
    if curr == target:
        print(start + 1, end + 1)
        break
else:
    print(-1)
