
n = int(input())
nums = list(map(int, input().split()))
seen = set(nums)
print(*[i for i in range(1, n+1) if i not in seen])
