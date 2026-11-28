Here is a Python code that solves the problem:

def find_max_difference(matrix):
    max_diff = float('-inf')
    for c in range(len(matrix)):
        for d in range(len(matrix[c])):
            if c > d:
                max_diff = max(max_diff, matrix[c][d] - matrix[a][b])
    return max_diff

def main():
    N = int(input().strip())
    matrix = []
    for _ in range(N):
        matrix.append(list(map(int, input().strip().split())))
    a, b = map(int, input().strip().split())
    print(find_max_difference(matrix))

if __name__ == "__main__":
    main()

This code first reads the matrix size N, then reads the matrix itself and the indices a and b. Then it calls the `find_max_difference` function with the matrix as argument, and prints the result. The `find_max_difference` function iterates over all pairs (c, d) in the matrix such that c > d, and updates the maximum difference found so far if necessary.