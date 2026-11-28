def longest_turbulent_subarray(arr):
    n = len(arr)
    dp = [1] * n
    max_len = 1

    for i in range(1, n):
        if arr[i] == arr[i - 1]:
            dp[i] = 2
        elif arr[i] > arr[i - 1]:
            dp[i] = dp[i - 1] + 1
        else:
            dp[i] = 2 if dp[i - 1] > 1 else 1

        max_len = max(max_len, dp[i])

    return max_len


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))

    print(longest_turbulent_subarray(arr))


if __name__ == "__main__":
    main()