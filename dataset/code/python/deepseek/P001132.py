Here is the Python code for the Climbing Stairs problem:

def climbing_stairs(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    if n == 2:
        return 2

    dp = [0] * (n + 1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 2

    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

def main():
    n = int(input())
    print(climbing_stairs(n))

if __name__ == "__main__":
    main()
This Python program uses dynamic programming to solve the Climbing Stairs problem. It first handles the base cases where `n=0`, `n=1`, and `n=2`. Then it creates a list `dp` to store the results of each subproblem, and fills it in using a for loop. The result of the nth subproblem is the sum of the results of the (n-1)th and (n-2)th subproblem, which is the key observation in the dynamic programming approach.