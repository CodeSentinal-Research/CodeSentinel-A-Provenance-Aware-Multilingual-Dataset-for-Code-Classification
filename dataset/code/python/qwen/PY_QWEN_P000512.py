import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    pushed = list(map(int, input_data[1:n+1]))
    popped = list(map(int, input_data[n+1:2*n+1]))
    stack = []
    j = 0
    for x in pushed:
        stack.append(x)
        while stack and j < n and stack[-1] == popped[j]:
            stack.pop()
            j += 1
    print("true" if not stack else "false")
solve()
