Here is the Python code for the problem:

def solve():
    N, M = map(int, input().split())
    matrix = [[0]*M for _ in range(N)]
    for i in range(N):
        row = list(map(int, input().split()))
        for j in range(M):
            matrix[i][j] = row[j]
    Q = int(input())
    for _ in range(Q):
        r1, c1, r2, c2 = map(int, input().split())
        r1, r2, c1, c2 = r1-1, r2-1, c1-1, c2-1
        print(sum(sum(row[c1+1:c2]) for row in matrix[r1:r2]))

def main():
    solve()

if __name__ == "__main__":
    main()

This code first reads the dimensions of the matrix and the number of queries, then it reads the matrix and the queries. For each query, it calculates the sum of the elements inside the rectangle defined by the two corners and prints the result.