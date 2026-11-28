Here is a Python code for the problem:

def countArrangement(N):
    def dfs(N, num):
        if N == 0:
            return 1
        res = 0
        for i in range(1, num+1):
            if num % i == 0 or i % num == 0:
                res += dfs(N-1, num-i)
        return res

    return dfs(N, N)

def main():
    N = int(input("Enter a number: "))
    print(countArrangement(N))

if __name__ == "__main__":
    main()

This code defines a function `countArrangement(N)` which counts the number of beautiful arrangements up to `N`. The function `dfs(N, num)` is a depth-first search function that tries to make a permutation of numbers from 1 to `num`. If `num` is divisible by `i` or `i` is divisible by `num`, it adds the number of arrangements for the remaining numbers(`N-1`) and `num-i`). The `main` function prompts user for an input, calls `countArrangement` with the input, and prints the result.