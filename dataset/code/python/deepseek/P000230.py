def find_common_elements():
    rows = int(input())
    cols = int(input())
    matrix = []

    for i in range(rows):
        row = list(map(int, input().split()))
        matrix.append(row)

    common_elements = set(matrix[0])

    for row in matrix:
        common_elements &= set(row)

    print(common_elements)


if __name__ == "__main__":
    find_common_elements()