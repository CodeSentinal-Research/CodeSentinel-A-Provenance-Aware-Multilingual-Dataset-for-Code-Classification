def find_target(nums, target):
    if len(nums) == 0:
        return False
    elif nums[0] == target:
        return True
    else:
        return find_target(nums[1:], target)

def main():
    nums = list(map(int, input().split()))
    target = nums[2]
    result = find_target(nums[1:], target)
    print(result)

if __name__ == "__main__":
    main()
In this code, we first define the `find_target` function, which is the recursive function for the problem. This function uses list slicing (`nums[1:]`) to remove the first element of the array (which is the target) and calls itself on the remaining array. If the array is empty (i.e., `len(nums) == 0`), we return `False`. If the first element of the array is the target, we return `True`. If the first element of the array is not the target, we return `False`.

Then, in the `main` function, we get the inputs (the number of elements, array elements, and the target element) and call the `find_target` function with the remaining array and the target. The result is printed.

Please note that this code assumes that the array is passed in as a list of strings, where each string is a number in the array. The code also assumes that the target is passed in as a string, because the prompt asks for a boolean output (true or false).