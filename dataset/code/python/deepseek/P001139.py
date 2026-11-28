Here is the Python code for the 0/1 Knapsack problem:

def knapSack(W, wt, val, n):
    K = [[0 for w in range(W+1)] for i in range(n+1)]
 
    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
    return K[n][W]

def main():
    N, W = map(int, input().split())
    val = [0]*N
    wt = [0]*N
    for i in range(N):
        val[i], wt[i] = map(int, input().split())
    print(knapSack(W, wt, val, N))

if __name__ == "__main__":
    main()

In the code above, the function `knapSack()` implements the 0/1 Knapsack algorithm. It initializes a 2D list `K` where `K[i][w]` represents the maximum value we can get for the first `i` items with a total weight `w`.

The `main()` function reads the number of items `N` and the capacity `W`, reads the values and weights of the items, and prints the maximum obtainable value.