s = input().strip()
stack = []
valid = True
for c in s:
    if c in "({[":
        stack.append(c)
    else:
        if not stack:
            valid = False
            break
        top = stack.pop()
        if (c == ')' and top != '(') or (c == '}' and top != '{') or (c == ']' and top != '['):
            valid = False
            break
print("true" if valid and not stack else "false")
