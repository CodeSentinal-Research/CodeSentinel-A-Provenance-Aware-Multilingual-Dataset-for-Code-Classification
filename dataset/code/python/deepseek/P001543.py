Here is the Python code for the given problem:

def min_sum_window(arr, k):
    if not arr or k > len(arr):
        return -1

    window_sum = sum(arr[:k])
    min_sum = window_sum

    for i in range(k, len(arr)):
        window_sum = window_sum - arr[i - k] + arr[i]
        min_sum = min(min_sum, window_sum)

    return min_sum


def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(min_sum_window(arr, k))


if __name__ == "__main__":
    main()

In this code, we first initialize the window sum to the sum of the first k elements in the array and the minimum sum to the window sum. Then we iterate over the rest of the array, updating the window sum and keeping track of the minimum sum. The minimum sum is the smallest window sum we have found. If there is no solution, we return -1.