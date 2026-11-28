# problem title : Greatest Common Divisor of Two Numbers
# Solve the stated task using standard input and standard output.
def gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return a

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(gcd(a, b))
