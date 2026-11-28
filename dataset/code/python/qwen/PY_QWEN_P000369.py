n = int(input())
strs = [input().strip() for _ in range(n)]
try:
    print(strs.index(""))
except ValueError:
    print(-1)
