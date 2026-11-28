n = int(input())
arr = list(map(int, input().split()))
stack = []
for x in arr:
    while stack and stack[-1] > 0 and x < 0:
        if stack[-1] < -x:
            stack.pop()
            continue
        elif stack[-1] == -x:
            stack.pop()
        break
    else:
        stack.append(x)
print(" ".join(map(str, stack)))
