Here is the Python code to solve the problem:

def count_derangements(n):
    der = [[0 for _ in range(n+1)] for _ in range(n+1)]
    
    der[0][0] = 1
    der[1][1] = 0
    der[1][0] = 1
    
    for i in range(2, n+1):
        for j in range(i+1):
            der[i][j] = (i - 1) * (der[i-1][j] + der[i-1][j-1])
            if j > 0:
                der[i][j] += der[i-1][j-1]
    
    return der[n][0]

def main():
    n = int(input())
    print(count_derangements(n))

if __name__ == "__main__":
    main()

This code first initializes a 2D array der, where der[i][j] represents the number of derangements of i elements that do not include jth element. The base cases are set for der[0][0] = 1 and der[1][0] = 1, because there is only one derangement for 0 and 1 element.

Then for each i from 2 to n (inclusive), der[i][j] is calculated as the product of i - 1 and the sum of der[i-1][j] and der[i-1][j-1]. If j > 0, der[i][j] is added to der[i-1][j-1].

Finally, the code returns der[n][0] which is the number of derangements of n elements.