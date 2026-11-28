num = input().strip()
k = int(input())
stack = []
for c in num:
    while k > 0 and stack and stack[-1] > c:
        stack.pop()
        k -= 1
    stack.append(c)
res = "".join(stack[:-k] if k > 0 else stack).lstrip('0')
print(res if res else "0")
