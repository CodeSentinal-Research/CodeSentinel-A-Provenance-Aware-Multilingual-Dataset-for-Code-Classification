Here is the Python code for the problem:

def maxSubarrayAfterDeletion(arr):
    n = len(arr)
    if n == 1:
        return 0
    if n == 2:
        return max(arr)

    dp = [0] * n
    dp2 = [0] * n

    dp[0] = arr[0]
    dp[1] = max(arr[0], arr[1])
    dp2[1] = max(dp[0], dp2[0])

    for i in range(2, n):
        dp[i] = max(dp[i - 1], dp2[i - 1])
        dp2[i] = max(dp[i - 2] + arr[i], dp2[i - 1])

    return max(dp[-2], dp2[-1])

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(maxSubarrayAfterDeletion(arr))

if __name__ == "__main__":
    main()

In this code, we use dynamic programming to solve the problem. We maintain two arrays, dp and dp2, to store the maximum sum of subarrays ending at current position. dp stores the maximum sum of subarrays ending at the previous position, dp2 stores the maximum sum of subarrays ending at the second previous position.

The base cases are when there are only two positions in the array. In this case, the maximum sum of a subarray of ones after deleting one element is the maximum of the two elements.

For the rest of the array, we update the dp and dp2 arrays accordingly.

Finally, we return the maximum sum of dp2 or dp. This is the maximum length of a subarray containing only ones after deleting one element.

The main function reads the number of elements in the array and the array itself, and then calls the maxSubarrayAfterDeletion function.