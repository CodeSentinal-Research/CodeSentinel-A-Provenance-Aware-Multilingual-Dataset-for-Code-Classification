Sure, I will provide the Python code with the main function and input handling.

def countSubarrays(nums):
    pos, neg, count, total = 0, 0, 0, 0
    for num in nums:
        if num > 0:
            pos += 1
            count += pos
            total += neg + 1 if neg > 0 else 0
        elif num < 0:
            neg += 1
            count += neg
            total += pos + 1 if pos > 0 else 0
        else:
            pos = neg = 0
            count = total = 0
    return total

def main():
    nums = [1, 3, 2, -5, -3, -1, 3, -2, 2, -1, -2, -3, -4, -1]
    print(countSubarrays(nums))

if __name__ == "__main__":
    main()
This code defines a function `countSubarrays` that counts the number of valid subarrays in an array. It uses two variables `pos` and `neg` to keep track of the number of positive and negative elements in the current subarray.

If the current number is positive, it increments `pos` and adds the number of elements up to the current position (`pos`) to `count`. If there are any negative elements before this, it increments `neg` and adds 1 (to the number of negative elements after the current position) to `total`.

If the current number is negative, it does the same as above, but with `neg` instead of `pos`.

If the current number is 0, it resets all variables to 0.

The `main` function is the entry point of the program and tests the `countSubarrays` function with a sample array.