
n = int(input())
nums = list(map(int, input().split()))
s = set(nums)
best = 0
for x in s:
    if x - 1 not in s:
        cur = 1
        while x + cur in s:
            cur += 1
        best = max(best, cur)
print(best)
