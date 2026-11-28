# problem title : Modular Subtraction
# Solve the stated task using standard input and standard output.
def mod_sub(a: int, b: int, m: int) -> int:
    return ((a % m) - (b % m) + m) % m

if __name__ == '__main__':
    a, b, m = map(int, input().split())
    print(mod_sub(a, b, m))
