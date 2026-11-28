n = int(input())
heights = list(map(int, input().split()))
stack = []
max_area = 0
for i in range(n + 1):
    h = heights[i] if i < n else 0
    start = i
    while stack and stack[-1][1] > h:
        idx, height = stack.pop()
        max_area = max(max_area, height * (i - idx))
        start = idx
    stack.append((start, h))
print(max_area)
