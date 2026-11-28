def add_matrices():
    rows, cols = map(int, input().split())
    matrix1 = [[int(col) for col in input().split()] for row in range(rows)]
    matrix2 = [[int(col) for col in input().split()] for row in range(rows)]

    result = [[matrix1[row][col] + matrix2[row][col] for col in range(cols)] for row in range(rows)]

    for row in result:
        print(' '.join(map(str, row)))

def main():
    add_matrices()

if __name__ == "__main__":
    main()