# problem title : Solve Linear Diophantine Equation
# Solve the stated task using standard input and standard output.
def ext_gcd(a: int, b: int):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def solve_diophantine(a: int, b: int, c: int):
    g, x, y = ext_gcd(a, b)
    if c % g != 0:
        return None
    factor = c // g
    return x * factor, y * factor

if __name__ == '__main__':
    a, b, c = map(int, input().split())
    sol = solve_diophantine(a, b, c)
    if sol is None:
        print("NO")
    else:
        print(f"YES\n{sol[0]} {sol[1]}")
