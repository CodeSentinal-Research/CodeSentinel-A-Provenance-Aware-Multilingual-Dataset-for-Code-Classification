import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    idx = 0
    q = int(input_data[idx]); idx += 1
    prod = [1]
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "add":
            val = int(input_data[idx]); idx += 1
            if val == 0:
                prod = [1]
            else:
                prod.append(prod[-1] * val)
        elif op == "getProduct":
            k = int(input_data[idx]); idx += 1
            if k >= len(prod):
                print(0)
            else:
                print(prod[-1] // prod[-1 - k])
solve()
