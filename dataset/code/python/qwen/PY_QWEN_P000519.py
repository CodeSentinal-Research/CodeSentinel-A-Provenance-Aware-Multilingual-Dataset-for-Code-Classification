import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    q = int(input_data[0])
    idx = 1
    s1, s2 = [], []
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "push":
            val = int(input_data[idx]); idx += 1
            s1.append(val)
        elif op == "pop":
            if not s2:
                while s1: s2.append(s1.pop())
            print(s2.pop() if s2 else -1)
        elif op == "peek":
            if not s2:
                while s1: s2.append(s1.pop())
            print(s2[-1] if s2 else -1)
        elif op == "empty":
            print("true" if not s1 and not s2 else "false")
solve()
