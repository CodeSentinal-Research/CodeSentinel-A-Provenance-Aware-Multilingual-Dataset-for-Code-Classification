# problem title : Modular Multiplicative Inverse
# Solve the stated task using standard input and standard output.
def extended_gcd(a: int, b: int):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

def mod_inverse(a: int, m: int) -> int:
    g, x, _ = extended_gcd(a, m)
    if g != 1:
        return -1
    return (x % m + m) % m

if __name__ == '__main__':
    a, m = map(int, input().split())
    print(mod_inverse(a, m))
