Here is the Python code:

def find_max(nums):
    if len(nums) == 1:
        return nums[0]
    else:
        max_other = find_max(nums[1:])
        return nums[0] if nums[0] > max_other else max_other

def main():
    nums = list(map(int, input().split()))[1:]
    print(find_max(nums))

if __name__ == "__main__":
    main()

This Python program will take an array of integers from user input and find the maximum element using recursion.

In the `find_max` function, if the length of the array is 1, we return the only element in the array, which is the maximum element.

If the array has more than 1 element, we recursively call `find_max` on the remaining array (excluding the first element) and find the maximum element in the remaining array.

Then, in the `main` function, we get user input as a list of integers and call `find_max` on the list of integers. The result is printed out.

Please note that you need to input the array of integers in the format 'n m1 m2 ... mn', where 'n' is the number of integers, and 'm1', 'm2', ..., 'mn' are the integers. For example, if you input '5 10 15 20 25', the program will find the maximum element in the array [10, 15, 20, 25].