# problem title : Toggle K-th Bit
# Solve the stated task using standard input and standard output.
def toggle_kth_bit(n: int, k: int) -> int:
    return n ^ (1 << k)

if __name__ == '__main__':
    n, k = map(int, input().split())
    print(toggle_kth_bit(n, k))
