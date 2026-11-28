def boundary_elements(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    for i in range(rows):
        for j in range(cols):
            if i == 0 or i == rows - 1 or j == 0 or j == cols - 1:
                print(matrix[i][j], end=' ')
        print()

def main():
    rows, cols = map(int, input().split())
    matrix = []

    for _ in range(rows):
        matrix.append(list(map(int, input().split())))

    boundary_elements(matrix)

if __name__ == "__main__":
    main()