import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:n+1]))
    stack = []
    for i in range(n):
        while stack and nums[stack[-1]] >= nums[i]:
            stack.pop()
        stack.append(i)
    max_w = 0
    for i in range(n - 1, -1, -1):
        while stack and nums[stack[-1]] <= nums[i]:
            max_w = max(max_w, i - stack.pop())
    print(max_w)
solve()
