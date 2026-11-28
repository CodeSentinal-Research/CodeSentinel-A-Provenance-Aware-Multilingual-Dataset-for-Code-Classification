Here is the Python code for the problem:

def findMin(nums):
    return min(nums)

nums = [3, 1, 2, 3, 3]
print(findMin(nums))  

The `min` function in Python finds the smallest item in an iterable like list or set. In the given code, it is used to find the minimum element in a rotated sorted array.

To handle the input, you can simply pass the rotated sorted array as an argument to the function. For example:

def handle_input():
    nums = list(map(int, input("Enter numbers separated by space: ").split()))
    print(f"You entered: {nums}")
    return nums

def findMin(nums):
    return min(nums)

def main():
    nums = handle_input()
    print(findMin(nums))

main()

In this code, the `handle_input` function handles the input and converts it into a list of integers. The `main` function calls `handle_input` and `findMin` to print the minimum element of the rotated sorted array.

Note: This code assumes that the input is a string of numbers separated by spaces. If the input is not a string of numbers, you will need to add error checking to handle that case.