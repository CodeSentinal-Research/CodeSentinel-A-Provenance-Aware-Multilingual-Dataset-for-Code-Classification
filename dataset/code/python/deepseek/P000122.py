Here is the Python code:

def max_subarray_sum(arr):
    max_sum = arr[0]
    current_sum = arr[0]

    for num in arr[1:]:
        current_sum = max(current_sum + num, num)
        max_sum = max(max_sum, current_sum)

    return max_sum


def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(max_subarray_sum(arr))


if __name__ == "__main__":
    main()

This code defines a function `max_subarray_sum` that finds the maximum subarray sum in a given list. It uses the Kadane's algorithm, which is a dynamic programming algorithm for solving the maximum subarray problem in linear time. The function `max_subarray_sum` iterates over the list of numbers, updating the current sum and the maximum sum as it goes.

The `main` function reads the input and calls the `max_subarray_sum` function with the input.

Note: You can run this code in a Python environment, or you can paste it into a Python file and run it. Make sure to handle the input and output as necessary.