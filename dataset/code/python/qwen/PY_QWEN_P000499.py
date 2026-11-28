s = input().strip()
stack = []
for c in s:
    if stack and stack[-1] != c and stack[-1].lower() == c.lower():
        stack.pop()
    else:
        stack.append(c)
print("".join(stack))
