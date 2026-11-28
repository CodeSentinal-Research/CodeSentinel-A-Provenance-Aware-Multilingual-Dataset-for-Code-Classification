Here is the Python code for the problem:

def numTrees(n):
    G = [0] * (n+1)
    G[0], G[1] = 1, 1

    for i in range(2, n+1):
        for j in range(1, i+1):
            G[i] += G[j-1] * G[i-j]

    return G[n]

n = int(input())
print(numTrees(n))
This Python code uses dynamic programming to solve the problem. It first creates an array G where G[i] is the number of unique BSTs that can be formed using values from 1 to i. It then iterates through the range from 2 to n+1 and for each i, it iterates through the range from 1 to i+1. For each j in the range, it adds G[j-1] * G[i-j] to G[i]. Finally, it returns G[n].

The input handling for this problem is done in the main function. It reads an integer n from the input and then calls the numTrees function with n. The result is printed out.