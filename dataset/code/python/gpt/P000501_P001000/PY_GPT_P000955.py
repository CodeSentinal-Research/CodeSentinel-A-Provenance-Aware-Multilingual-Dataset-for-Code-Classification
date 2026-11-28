# problem title : Modular Inverse Using Extended Euclid
# Solve the stated task using standard input and standard output.
def ext_gcd(a: int, b: int):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def mod_inv(a: int, m: int) -> int:
    g, x, _ = ext_gcd(a, m)
    if g != 1:
        return -1
    return (x % m + m) % m

if __name__ == '__main__':
    a, m = map(int, input().split())
    print(mod_inv(a, m))
