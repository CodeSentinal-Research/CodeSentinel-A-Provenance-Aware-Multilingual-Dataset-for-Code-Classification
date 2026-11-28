s = input().strip()
stack = []
for c in s:
    if c == '(':
        stack.append([])
    elif c == ')':
        res = stack.pop()
        res.reverse()
        if stack:
            stack[-1].extend(res)
        else:
            stack.append(res)
    else:
        if stack:
            stack[-1].append(c)
        else:
            stack.append([c])
print("".join(stack[0]) if stack else "")
