# problem title : Find One Diophantine Solution
# Solve the stated task using standard input and standard output.
def ext_gcd(a: int, b: int):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def find_one_solution(a: int, b: int, c: int):
    g, x, y = ext_gcd(a, b)
    if c % g != 0:
        return -1, -1
    f = c // g
    return x * f, y * f

if __name__ == '__main__':
    a, b, c = map(int, input().split())
    x, y = find_one_solution(a, b, c)
    print(f"{x} {y}")
