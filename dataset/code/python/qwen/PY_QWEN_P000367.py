n = int(input())
strs = [input().strip() for _ in range(n)]
print(strs.index(min(strs, key=len)))
