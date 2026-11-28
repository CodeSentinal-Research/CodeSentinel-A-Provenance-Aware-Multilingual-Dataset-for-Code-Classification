def solve(n, m, constraints):
    matrix = [[0]*n for _ in range(n)]
    num = 1
    for i in range(n):
        for j in range(n):
            if matrix[i][j] == 0:
                matrix[i][j] = num
                num += 1
            if num == n*n:
                return matrix
    return "IMPOSSIBLE"

def main():
    n = int(input().strip())
    m = int(input().strip())
    constraints = [input().strip() for _ in range(m)]
    result = solve(n, m, constraints)
    if isinstance(result, str):
        print(result)
    else:
        for row in result:
            print(' '.join(map(str, row)))

if __name__ == "__main__":
    main()