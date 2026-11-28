import math

def count_diophantine_solutions(a: int, b: int, c: int, minx: int, maxx: int, miny: int, maxy: int) -> int:
    """Solves 'Count Diophantine Solutions in Range' by applying optimal Mathematics - Diophantine Equations logic."""
    def ext_gcd(a, b):
        """Computes the Greatest Common Divisor (GCD) using Euclidean algorithm."""
        if b == 0: return a, 1, 0
        g, x1, y1 = ext_gcd(b, a % b)
        return g, y1, x1 - (a // b) * y1

    g, x, y = ext_gcd(abs(a), abs(b))
    if c % g != 0:
        return 0

    x *= (c // g) * (1 if a >= 0 else -1)
    y *= (c // g) * (1 if b >= 0 else -1)

    step_x = b // g
    step_y = a // g

    def shift(x, y, a, b, cnt):
        return x + cnt * b, y - cnt * a

    # Bound for x
    sign_x = 1 if step_x > 0 else -1
    lx = math.ceil((minx - x) / step_x) if step_x > 0 else math.ceil((maxx - x) / step_x)
    rx = math.floor((maxx - x) / step_x) if step_x > 0 else math.floor((minx - x) / step_x)

    # Bound for y
    ly = math.ceil((y - maxy) / step_y) if step_y > 0 else math.ceil((y - miny) / step_y)
    ry = math.floor((y - miny) / step_y) if step_y > 0 else math.floor((y - maxy) / step_y)

    l = max(lx, ly)
    r = min(rx, ry)
    return max(0, r - l + 1)

if __name__ == '__main__':
    a, b, c = map(int, input().split())
    minx, maxx, miny, maxy = map(int, input().split())
    print(count_diophantine_solutions(a, b, c, minx, maxx, miny, maxy))