Here is a Python solution using dynamic programming:

def solve(n, maxHeights):
    dp = [0] * (n+1)
    dp[1] = maxHeights[0]
    for i in range(2, n+1):
        dp[i] = max(maxHeights[i-1], dp[i-1])
    return dp[n]

def main():
    n = int(input())
    maxHeights = list(map(int, input().split()))
    print(solve(n, maxHeights))

if __name__ == "__main__":
    main()

This Python program first takes the number of towers `n` and the maximum heights of each tower as inputs. It then constructs a dynamic programming array `dp` where `dp[i]` represents the maximum height that can be achieved with `i` towers. 

The base case `dp[1] = maxHeights[0]` is set for `i = 1`. For `i = 2` to `n`, it iterates through all the possible towers and calculates the maximum height by taking the maximum between the current tower's height and the maximum height achieved by `i-1` towers.

Finally, it returns the maximum possible sum of tower heights, which is `dp[n]`. 

The `main` function handles the input and output. It first reads the number of towers, and then the maximum heights of each tower. It then calls the `solve` function to get the maximum possible sum of tower heights.