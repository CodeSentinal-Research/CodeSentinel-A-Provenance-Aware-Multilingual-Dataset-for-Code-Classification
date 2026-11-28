# problem title : Count Trailing Zeros in Binary Representation
# Solve the stated task using standard input and standard output.
def count_trailing_zeros(n: int) -> int:
    if n == 0:
        return 32
    return (n & -n).bit_length() - 1

if __name__ == '__main__':
    n = int(input())
    print(count_trailing_zeros(n))
