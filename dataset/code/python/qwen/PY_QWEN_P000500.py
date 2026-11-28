n = int(input())
ops = [input().strip() for _ in range(n)]
depth = 0
for op in ops:
    if op == "../":
        if depth > 0: depth -= 1
    elif op == "./":
        continue
    else:
        depth += 1
print(depth)
