# problem title : Linear Congruence Solver
# Solve the stated task using standard input and standard output.
def ext_gcd(a: int, b: int):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def solve_congruence(a: int, b: int, m: int):
    g, x, _ = ext_gcd(a, m)
    if b % g != 0:
        return []
    x0 = (x * (b // g)) % m
    x0 = (x0 + m) % m
    step = m // g
    return sorted([(x0 + i * step) % m for i in range(g)])

if __name__ == '__main__':
    a, b, m = map(int, input().split())
    res = solve_congruence(a, b, m)
    if not res:
        print(-1)
    else:
        print(" ".join(map(str, res)))
