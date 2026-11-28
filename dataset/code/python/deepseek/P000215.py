Here is the Python code for the problem:

def max_average(n, k, nums):
    if k > n:
        return -1

    window_sum = sum(nums[:k])
    max_sum = window_sum

    for i in range(k, n):
        window_sum = window_sum - nums[i - k] + nums[i]
        max_sum = max(max_sum, window_sum)

    return max_sum / k


def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_average(n, k, nums))


if __name__ == "__main__":
    main()

In this code, we define a function `max_average` that takes in the number of elements `n` and the size of the window `k`, and the list of elements `nums`. It calculates the sum of the first `k` elements in the window, and then iteratively updates the window sum and max sum as we slide the window. Finally, it returns the maximum average by dividing the max sum by the window size `k`.

In the `main` function, we take the number of elements and the size of the window from the input, and the list of elements, and print the result of the `max_average` function.