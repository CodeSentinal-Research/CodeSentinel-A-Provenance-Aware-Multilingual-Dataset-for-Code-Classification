rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
heights = [0] * cols
max_area = 0
for i in range(rows):
    for j in range(cols):
        if matrix[i][j] == 1:
            heights[j] += 1
        else:
            heights[j] = 0
    stack = []
    for j in range(cols + 1):
        h = heights[j] if j < cols else 0
        start = j
        while stack and stack[-1][1] > h:
            idx, height = stack.pop()
            max_area = max(max_area, height * (j - idx))
            start = idx
        stack.append((start, h))
print(max_area)
