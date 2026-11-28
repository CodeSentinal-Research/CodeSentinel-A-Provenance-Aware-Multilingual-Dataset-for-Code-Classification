def count_equal_pairs(matrix):
    count = 0
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            for k in range(j+1, len(matrix[i])):
                if matrix[i][j] == matrix[i][k]:
                    count += 1
    return count

def main():
    N = int(input().strip())
    matrix = [list(map(int, input().strip().split())) for _ in range(N)]
    print(count_equal_pairs(matrix))

main()