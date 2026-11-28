import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    q = int(input_data[0])
    idx = 1
    stack = []
    for i in range(q):
        price = int(input_data[idx]); idx += 1
        span = 1
        while stack and stack[-1][0] <= price:
            span += stack.pop()[1]
        stack.append((price, span))
        print(span)
solve()
