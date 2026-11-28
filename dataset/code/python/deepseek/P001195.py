def maxAlternatingSubsequenceSum(arr):
    n = len(arr)
    dp = [0]*n
    dp[0] = arr[0]
    for i in range(1,n):
        dp[i] = max(dp[i-1], arr[i])
        if i > 1:
            dp[i] = max(dp[i], dp[i-2] + arr[i])
    return dp[-1]

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(maxAlternatingSubsequenceSum(arr))

if __name__ == "__main__":
    main()