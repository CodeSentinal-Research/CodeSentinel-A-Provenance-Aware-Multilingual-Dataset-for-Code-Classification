Here is the Python code for the problem:

def count_ways(N, K):
    if N == 1:
        return K
    elif N == 2:
        return K * K
    else:
        dp = [0] * N
        dp[0] = K
        dp[1] = K * K
        for i in range(2, N):
            dp[i] = (dp[i-1] + dp[i-2]) * (K-1)
        return dp[N-1]

def main():
    N, K = map(int, input().split())
    print(count_ways(N, K))

if __name__ == "__main__":
    main()

This program works by first checking if the number of fence posts is 1 or 2. If it is, it simply returns the number of ways to paint the fence. If it is more than 2, it uses dynamic programming to calculate the number of ways to paint the fence. It does this by creating a list of length N, and initializing the first two elements to the number of ways to paint the fence for one color and for two colors. Then, for each remaining element, it calculates the number of ways by adding the number of ways to paint the fence for one color and two colors that were not painted the same color before (since there are K-1 ways to paint the last color), and multiplying this by (K-1).