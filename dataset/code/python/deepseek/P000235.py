def zigzag(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    result = []
    for r in range(rows):
        for c in range(cols):
            if r % 2 == 0:
                result.append(matrix[r][c])
            else:
                result.append(matrix[r][cols - c - 1])
    return result

def main():
    rows, cols = map(int, input().split())
    matrix = []
    for _ in range(rows):
        matrix.append(list(map(int, input().split())))
    print(zigzag(matrix))

if __name__ == "__main__":
    main()