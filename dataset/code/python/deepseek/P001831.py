def numTrees(n):
    G = [0] * (n + 1)
    G[0] = 1
    G[1] = 1

    for i in range(2, n + 1):
        for j in range(1, i + 1):
            G[i] += G[j-1] * G[i-j]

    return G[n]

def main():
    n = int(input())
    print(numTrees(n))

if __name__ == "__main__":
    main()
In this python program, I have defined a function `numTrees(n)` that calculates the number of unique Binary Search Trees that can be formed using `n` keys. It uses dynamic programming to store the results of each problem so that we don't have to recalculate them multiple times.

The main function takes an integer `n` as input, calls `numTrees(n)` and prints the result.