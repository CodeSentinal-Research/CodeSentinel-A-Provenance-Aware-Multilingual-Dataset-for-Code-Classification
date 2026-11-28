n = int(input())
ops = [input().strip() for _ in range(n)]
stack = []
for op in ops:
    if op == '+':
        stack.append(stack[-1] + stack[-2])
    elif op == 'D':
        stack.append(stack[-1] * 2)
    elif op == 'C':
        stack.pop()
    else:
        stack.append(int(op))
print(sum(stack))
