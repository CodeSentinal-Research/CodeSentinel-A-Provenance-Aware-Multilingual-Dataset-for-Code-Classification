Here is the Python code for the problem:

def count_arithmetic_subsequences(arr):
    n = len(arr)
    dp = [dict() for _ in range(n)]
    ans = 0

    for i in range(n):
        for j in range(i):
            diff = arr[i] - arr[j]
            if diff in dp[j]:
                dp[i][diff] = dp[i].get(diff, 0) + dp[j].get(diff, 0)
                ans += dp[j][diff]
            else:
                dp[i][diff] = dp[i].get(diff, 0) + dp[j].get(diff, 0) + 1

    return ans

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(count_arithmetic_subsequences(arr))

if __name__ == "__main__":
    main()

This code first reads the number of integers N and the integers themselves. It then calls the `count_arithmetic_subsequences` function, which calculates and returns the total number of arithmetic subsequences. The `count_arithmetic_subsequences` function uses dynamic programming to solve the problem. It uses a 2D dictionary `dp` to store the count of arithmetic subsequences for each difference between numbers. It also uses a variable `ans` to store the total count of arithmetic subsequences.