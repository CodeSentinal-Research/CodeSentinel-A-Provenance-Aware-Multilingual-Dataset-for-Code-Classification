# problem title : Count Leading Zeros
# Solve the stated task using standard input and standard output.
def count_leading_zeros(n: int) -> int:
    if n == 0:
        return 32
    return 32 - len(bin(n)[2:])

if __name__ == '__main__':
    n = int(input())
    print(count_leading_zeros(n))
