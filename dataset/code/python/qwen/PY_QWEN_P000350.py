s = input().strip()
k = int(input())
stack = []
for c in s:
    if stack and stack[-1][0] == c:
        stack[-1][1] += 1
        if stack[-1][1] == k:
            stack.pop()
    else:
        stack.append([c, 1])
print("".join(c * cnt for c, cnt in stack))
