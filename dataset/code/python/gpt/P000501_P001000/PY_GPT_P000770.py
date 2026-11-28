# problem title : Recursive Matrix Chain Multiplication
# Solve the stated task using standard input and standard output.
import sys
def mcm(dims):
    memo = {}
    def solve(i, j):
        if i >= j: return 0
        if (i, j) in memo: return memo[(i, j)]
        min_cost = float('inf')
        for k in range(i, j):
            cost = solve(i, k) + solve(k + 1, j) + dims[i - 1] * dims[k] * dims[j]
            min_cost = min(min_cost, cost)
        memo[(i, j)] = min_cost
        return min_cost
    return solve(1, len(dims) - 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        dims = list(map(int, tokens[1:1+n]))
        print(mcm(dims))
if __name__ == '__main__':
    main()
