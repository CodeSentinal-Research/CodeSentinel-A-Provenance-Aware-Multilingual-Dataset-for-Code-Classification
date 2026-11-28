def longest_increasing_subsequence(arr):
    if not arr:
        return 0

    dp = [1] * len(arr)
    for i in range(1, len(arr)):
        if arr[i] > arr[i-1]:
            dp[i] = dp[i-1] + 1

    return max(dp)

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(longest_increasing_subsequence(arr))

main()