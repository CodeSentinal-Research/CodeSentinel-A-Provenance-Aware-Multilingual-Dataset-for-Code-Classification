Here is the Python code for the problem:

def numTrees(n):
    G = [0] * (n+1)
    G[0], G[1] = 1, 1

    for i in range(2, n+1):
        for j in range(1, i+1):
            G[i] += G[j-1] * G[i-j]

    return G[n]

def main():
    n = int(input("Enter the value of N: "))
    print("The number of unique Binary Search Trees is: ", numTrees(n))

if __name__ == "__main__":
    main()

In the code above, we first define the `numTrees` function which computes the number of unique Binary Search Trees. The `G` list is used to store the results of the computation and `numTrees` iterates through all possible splits of the input list (from 1 to `n`), computing the number of unique BSTs for each possible split and storing these counts in `G`.

The `main` function handles the input and output of the program. It reads the input `n`, computes the number of unique BSTs using `numTrees`, and prints the result.

The `if __name__ == "__main__":` clause ensures that the main function is only run when the script is run directly, not when it is imported as a module.