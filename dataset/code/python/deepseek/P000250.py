def calc_det(matrix):
    if len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

    det = 0
    for c in range(len(matrix)):
        sub_matrix = [[matrix[i][j] for j in range(len(matrix[i])) if j != c] for i in range(len(matrix)) if i != c]
        det += ((-1) ** c) * matrix[0][c] * calc_det(sub_matrix)

    return det

def main():
    N = int(input())
    matrix = [[int(j) for j in input().split()] for i in range(N)]
    print(calc_det(matrix))

if __name__ == "__main__":
    main()