s = input().strip()
stack = []
for c in s.split(','):
    if c == '#':
        if not stack:
            print("false")
            break
        stack.pop()
        if not stack:
            print("false")
            break
    else:
        stack.append(c)
else:
    print("true" if len(stack) == 1 else "false")
