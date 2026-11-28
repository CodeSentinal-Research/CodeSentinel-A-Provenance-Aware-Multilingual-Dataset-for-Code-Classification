Here is the Python code with the main function and input handling:

def is_sorted(nums):
    if len(nums) == 0:
        return True
    elif len(nums) == 1:
        return True
    elif nums[0] <= nums[1]:
        return is_sorted(nums[1:])
    else:
        return False

def main():
    nums = input("Enter a list of integers separated by space: ")
    nums = list(map(int, nums.split()))
    if is_sorted(nums):
        print("True")
    else:
        print("False")

if __name__ == "__main__":
    main()

In this code, we define a recursive function `is_sorted` that checks if the input list is sorted. If the list is empty or contains one element, it is sorted, so we return true. If the first element is not less than or equal to the second, it means the list is not sorted, so we return false. If the first element is less than the second, we recursively call `is_sorted` on the rest of the list.

In the `main` function, we take a string input from the user, split it by space, convert the string into a list of integers, and pass it to the `is_sorted` function. We then print the result.

This code assumes that the input is always a list of integers, separated by spaces.