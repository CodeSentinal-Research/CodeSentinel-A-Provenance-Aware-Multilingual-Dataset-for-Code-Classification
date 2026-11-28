import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    q = int(input_data[0])
    idx = 1
    stack = []
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "push":
            val = int(input_data[idx]); idx += 1
            stack.append(val)
        elif op == "pop":
            print(stack.pop() if stack else -1)
        elif op == "top":
            print(stack[-1] if stack else -1)
        elif op == "empty":
            print("true" if not stack else "false")
solve()
