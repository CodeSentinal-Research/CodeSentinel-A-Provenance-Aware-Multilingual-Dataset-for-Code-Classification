path = input().strip()
parts = path.split('/')
stack = []
for p in parts:
    if p == '' or p == '.':
        continue
    elif p == '..':
        if stack:
            stack.pop()
    else:
        stack.append(p)
print('/' + '/'.join(stack))
