def search_in_matrix(matrix, target):
    rows = len(matrix)
    cols = len(matrix[0])

    start = 0
    end = rows * cols - 1

    while start <= end:
        mid = (start + end) // 2
        mid_val = matrix[mid // cols][mid % cols]

        if mid_val == target:
            return "Found"
        elif mid_val < target:
            start = mid + 1
        else:
            end = mid - 1

    return "Not Found"

def main():
    rows, cols, target = map(int, input().split())

    matrix = []
    for _ in range(rows):
        row = list(map(int, input().split()))
        matrix.append(row)

    print(search_in_matrix(matrix, target))

if __name__ == "__main__":
    main()