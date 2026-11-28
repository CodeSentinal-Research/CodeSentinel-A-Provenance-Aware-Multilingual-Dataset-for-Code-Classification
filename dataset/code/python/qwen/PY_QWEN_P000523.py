import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    vals = list(map(int, input_data[1:n+1]))
    stack = []
    for v in reversed(vals):
        while stack and stack[-1] < v:
            stack.pop()
        stack.append(v)
    print(" ".join(map(str, reversed(stack))))
solve()
