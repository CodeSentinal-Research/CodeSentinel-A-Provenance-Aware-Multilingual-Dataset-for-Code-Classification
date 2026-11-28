Here is the Python code for the problem:

def max_value(n, index, max_sum):
    left, right = 0, max_sum
    while left < right:
        mid = (left + right + 1) // 2
        if mid + mid + index > max_sum:
            right = mid - 1
        else:
            left = mid
    return left + index

This function is a binary search algorithm that tries to find the maximum value such that the sum of elements is not exceeding `max_sum` at the given index. It starts from `0` and tries to increase the mid value until the sum of elements `mid + mid + index` is greater than `max_sum`.

The time complexity of this function is `O(log(max_sum))`, which is better than the naive solution `O(n)`.

In the main function, you can input the length of the array `n`, the index `index` and the maximum sum `max_sum` as follows:

def main():
    n, index, max_sum = 3, 2, 9
    print(max_value(n, index, max_sum))

if __name__ == "__main__":
    main()

Please replace `n`, `index`, and `max_sum` with your actual values when you run the `main` function.