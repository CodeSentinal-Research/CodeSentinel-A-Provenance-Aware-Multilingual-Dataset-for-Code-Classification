s = input().strip()
stack = []
seen = set()
last_occ = {c: i for i, c in enumerate(s)}
for i, c in enumerate(s):
    if c not in seen:
        while stack and stack[-1] > c and last_occ[stack[-1]] > i:
            seen.remove(stack.pop())
        stack.append(c)
        seen.add(c)
print("".join(stack))
