Here's the Python code:

def quicksort(nums):
    if len(nums) <= 1:
        return nums
    pivot = nums[len(nums) // 2]
    left = [x for x in nums if x < pivot]
    middle = [x for x in nums if x == pivot]
    right = [x for x in nums if x > pivot]
    return quicksort(left) + middle + quicksort(right)

def main():
    n = int(input("Enter the size of the array: "))
    nums = list(map(int, input("Enter the elements of the array: ").split()))
    print(quicksort(nums))

main()

This code defines a function `quicksort` which is a recursive implementation of the QuickSort algorithm. The `main` function prompts the user for the size of the array and the array elements, then calls `quicksort` on the user's input.

Please note that the code doesn't handle the input size constraint. You should add error checking for the input size to ensure it's within the required range.