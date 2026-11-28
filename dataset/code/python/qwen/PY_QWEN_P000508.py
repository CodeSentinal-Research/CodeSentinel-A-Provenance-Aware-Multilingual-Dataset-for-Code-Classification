import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    heights = list(map(int, input_data[1:n+1]))
    res = [0] * n
    stack = []
    for i in range(n - 1, -1, -1):
        count = 0
        while stack and heights[stack[-1]] < heights[i]:
            count += res[stack.pop()] + 1
        if stack and heights[stack[-1]] > heights[i]:
            count += 1
        res[i] = count
        stack.append(i)
    print(" ".join(map(str, res)))
solve()
