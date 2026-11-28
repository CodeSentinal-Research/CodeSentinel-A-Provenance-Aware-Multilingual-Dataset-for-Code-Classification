import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    q = int(input_data[0])
    idx = 1
    stack = []
    min_stack = []
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "push":
            val = int(input_data[idx]); idx += 1
            stack.append(val)
            if not min_stack:
                min_stack.append(val)
            else:
                min_stack.append(min(val, min_stack[-1]))
        elif op == "pop":
            stack.pop()
            min_stack.pop()
        elif op == "top":
            print(stack[-1])
        elif op == "getMin":
            print(min_stack[-1])
solve()
