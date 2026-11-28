n = int(input())
strs = [input().strip() for _ in range(n)]
print(strs.index(max(strs, key=len)))
