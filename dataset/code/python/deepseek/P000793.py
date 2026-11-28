Here is the Python code for the given problem:

def count_subarrays(nums, k, n):
    count = 0
    for i in range(n):
        odd_count = 0
        for j in range(i, n):
            if nums[j] % 2 == 1:
                odd_count += 1
            if odd_count == k:
                count += 1
            if odd_count > k:
                break
    return count

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    k = int(input())
    print(count_subarrays(nums, k, n))

if __name__ == "__main__":
    main()

In this Python program, a function `count_subarrays` is defined to find the number of contiguous subarrays containing exactly `k` odd numbers in a given array `nums`.

The function `main` is defined to handle the input, call the `count_subarrays` function and print the result.

The `main` function reads the number of elements `n` and the elements themselves `nums` and the number `k`.

The `count_subarrays` function loops through `nums`, and for each element, it keeps track of the count of odd numbers and increments the count if the count equals to `k`.

The `main` function calls the `count_subarrays` function with the inputs and then prints the result.