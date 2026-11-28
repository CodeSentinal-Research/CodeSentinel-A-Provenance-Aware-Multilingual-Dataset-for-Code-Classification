def find_first_even(nums):
    for i, num in enumerate(nums):
        if num % 2 == 0:
            return i
    return -1