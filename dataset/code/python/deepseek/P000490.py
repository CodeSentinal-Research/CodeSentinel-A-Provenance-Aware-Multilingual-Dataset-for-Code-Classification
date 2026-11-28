def backspaceCompare(s, t):
    def build(s):
        stack = []
        for c in s:
            if c == '#':
                if stack:
                    stack.pop()
            else:
                stack.append(c)
        return ''.join(stack)

    return build(s) == build(t)

s = input("Enter the first string: ")
t = input("Enter the second string: ")
print(backspaceCompare(s, t))