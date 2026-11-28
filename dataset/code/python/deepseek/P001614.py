Here is the Python code for the problem:

def get_max_sum(matrix):
    N = len(matrix)
    M = len(matrix[0])
    max_sum = float('-inf')

    for top in range(N):
        temp = [0]*M
        for bottom in range(top, N):
            for i in range(M):
                temp[i] += matrix[bottom][i]
            curr_sum = sum_max_subarray(temp)
            max_sum = max(max_sum, curr_sum)

    return max_sum

def sum_max_subarray(temp):
    max_sum = temp[0]
    curr_sum = max_sum
    for i in range(1, len(temp)):
        curr_sum = max(temp[i], curr_sum + temp[i])
        max_sum = max(max_sum, curr_sum)

    return max_sum

def main():
    N, M = map(int, input().split())
    matrix = []
    for _ in range(N):
        row = list(map(int, input().split()))
        matrix.append(row)

    print(get_max_sum(matrix))

if __name__ == "__main__":
    main()

This code first reads the size of the matrix and the matrix itself. It then calls the `get_max_sum` function, which calculates the maximum sum of a submatrix in the given matrix. Finally, it prints out the maximum sum of the submatrix.