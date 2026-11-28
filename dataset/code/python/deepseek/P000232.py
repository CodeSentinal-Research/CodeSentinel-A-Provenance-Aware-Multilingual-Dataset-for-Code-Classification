def find_median():
    rows, cols = map(int, input().split())

    matrix = [[int(j) for j in input().split()] for i in range(rows)]

    flat_list = [num for sublist in matrix for num in sublist]

    flat_list.sort()

    if len(flat_list) % 2 == 0:
        median = (flat_list[len(flat_list) // 2] + flat_list[len(flat_list) // 2 - 1]) / 2
    else:
        median = flat_list[len(flat_list) // 2]

    print(median)

if __name__ == "__main__":
    find_median()