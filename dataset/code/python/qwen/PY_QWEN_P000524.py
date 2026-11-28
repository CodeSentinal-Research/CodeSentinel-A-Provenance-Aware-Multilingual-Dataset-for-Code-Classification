import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    maxH = list(map(int, input_data[1:n+1]))
    left = [0] * n
    stack = []
    for i in range(n):
        while stack and maxH[stack[-1]] >= maxH[i]:
            stack.pop()
        left[i] = stack[-1] if stack else -1
        stack.append(i)
    right = [0] * n
    stack = []
    for i in range(n - 1, -1, -1):
        while stack and maxH[stack[-1]] >= maxH[i]:
            stack.pop()
        right[i] = stack[-1] if stack else n
        stack.append(i)
    ans = 0
    for i in range(n):
        l_len = i - left[i]
        r_len = right[i] - i
        ans += maxH[i] + (l_len - 1) * l_len // 2 + (r_len - 1) * r_len // 2
    print(ans)
solve()
