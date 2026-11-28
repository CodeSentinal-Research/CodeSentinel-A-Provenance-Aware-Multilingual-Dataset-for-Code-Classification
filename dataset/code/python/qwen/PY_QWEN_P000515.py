import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    cars = []
    idx = 1
    for _ in range(n):
        p = int(input_data[idx]); s = int(input_data[idx+1])
        cars.append((p, s))
        idx += 2
    res = [-1.0] * n
    stack = []
    for i in range(n - 1, -1, -1):
        p, s = cars[i]
        while stack:
            j, pj, sj = stack[-1]
            if s <= sj:
                stack.pop()
            else:
                res[i] = (pj - p) / (s - sj)
                if res[j] != -1.0 and res[i] >= res[j]:
                    stack.pop()
                else:
                    break
        stack.append((i, p, s))
    print(" ".join(map(str, res)))
solve()
