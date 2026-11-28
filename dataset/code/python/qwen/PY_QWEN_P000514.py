s = input().strip()
stack = []
for c in reversed(s):
    if c == '?':
        stack.append(c)
    elif c == ':':
        continue
    else:
        if stack and stack[-1] == '?':
            stack.pop()
            true_val = stack.pop()
            stack.pop()
            false_val = stack.pop()
            if c == 'T':
                stack.append(true_val)
            else:
                stack.append(false_val)
        else:
            stack.append(c)
print(stack[0])
