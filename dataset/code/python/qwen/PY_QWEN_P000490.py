s = input().strip()
t = input().strip()
def build(s):
    stack = []
    for c in s:
        if c == '#':
            if stack: stack.pop()
        else:
            stack.append(c)
    return "".join(stack)
print("true" if build(s) == build(t) else "false")
