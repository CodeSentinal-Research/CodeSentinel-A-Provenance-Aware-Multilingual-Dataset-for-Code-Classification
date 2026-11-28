# problem title : Merge Two Congruence Equations
# Solve the stated task using standard input and standard output.
def ext_gcd(a: int, b: int):
    if b == 0: return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def merge_congruences(r1: int, m1: int, r2: int, m2: int):
    g, p, q = ext_gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return -1, -1
    mod = (m1 * m2) // g
    step = (r2 - r1) // g
    k = (p * step) % (m2 // g)
    ans = (r1 + k * m1) % mod
    return (ans % mod + mod) % mod, mod

if __name__ == '__main__':
    r1, m1, r2, m2 = map(int, input().split())
    r, m = merge_congruences(r1, m1, r2, m2)
    if r == -1:
        print("-1")
    else:
        print(f"{r} {m}")
