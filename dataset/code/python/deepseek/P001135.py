Here is the Python code:

def max_sum(arr):
    if len(arr) == 0:
        return 0
    elif len(arr) == 1:
        return arr[0]
    elif len(arr) == 2:
        return max(arr[0], arr[1])

    dp = [0]*len(arr)
    dp[0] = arr[0]
    dp[1] = max(arr[0], arr[1])

    for i in range(2, len(arr)):
        dp[i] = max(dp[i-1], dp[i-2]+arr[i])

    return dp[-1]


if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(max_sum(arr))

This code defines a function `max_sum(arr)` that takes as input a list of integers `arr`. If `arr` is empty, the function returns 0. If `arr` has one element, the function returns that element. If `arr` has two elements, the function returns the maximum of those two elements.

Otherwise, the function creates a list `dp` of length `arr`, where `dp[i]` is the maximum sum of elements up to and including `arr[i]`. It initializes `dp[0]` to be the first element of `arr`, and `dp[1]` to be the maximum of the first two elements of `arr`.

Then, the function iterates over `arr` from the third element up to the end of `arr`, updating `dp[i]` to be the maximum of the previous element in `dp` (i.e., `dp[i-1]`) and the sum of the current element and the previous element in `dp` (i.e., `dp[i-2] + arr[i]`).

Finally, the function returns the maximum sum of elements up to and including the last element in `dp` (i.e., `dp[-1]`).

In the main part of the code, the code reads the number of elements `n` and the elements of the list from the standard input. It then calls `max_sum(arr)` with the list of elements, and prints the result.