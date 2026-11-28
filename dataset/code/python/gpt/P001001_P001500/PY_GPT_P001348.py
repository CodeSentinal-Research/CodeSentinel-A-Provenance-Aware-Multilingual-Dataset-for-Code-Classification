# problem title : Fill the Matrix
# Solve the stated task using standard input and standard output.
def min_time_to_fill_matrix(n: int, m: int, r: int, c: int) -> int:
    return max(r - 1, n - r) + max(c - 1, m - c)

if __name__ == '__main__':
    n, m, r, c = map(int, input().split())
    print(min_time_to_fill_matrix(n, m, r, c))
