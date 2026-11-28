s = input().strip()
stack = [0]
for c in s:
    if c == '(':
        stack.append(0)
    elif c == ')':
        val = stack.pop()
        stack[-1] += max(2 * val, 1)
    else:
        stack[-1] += 1
print(stack[0])
