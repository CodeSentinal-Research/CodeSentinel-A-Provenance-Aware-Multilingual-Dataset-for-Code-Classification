# problem title : Minimum Positive Bézout Solution
# Solve the stated task using standard input and standard output.
def ext_gcd(a: int, b: int):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def min_positive_bezout(a: int, b: int):
    g, x, y = ext_gcd(a, b)
    step_x = b // g
    step_y = a // g
    x = (x % step_x + step_x) % step_x
    if x == 0:
        x += step_x
    y = (g - a * x) // b
    return x, y

if __name__ == '__main__':
    a, b = map(int, input().split())
    x, y = min_positive_bezout(a, b)
    print(f"{x} {y}")
