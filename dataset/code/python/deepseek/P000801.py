def solve(N, M, grid, K):
    prefix_sum = [[0 for _ in range(M+1)] for _ in range(N+1)]

    for i in range(1, N+1):
        for j in range(1, M+1):
            prefix_sum[i][j] = grid[i-1][j-1] + prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1]

    result = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(1, N+1):
        for j in range(1, M+1):
            for x in range(max(0, i-K), min(N, i)+1):
                for y in range(max(0, j-K), min(M, j)+1):
                    result[i-1][j-1] += prefix_sum[x][y]

    return result

def main():
    N = 5
    M = 5
    grid = [[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5]]
    K = 1
    result = solve(N, M, grid, K)
    for row in result:
        print(row)

main()