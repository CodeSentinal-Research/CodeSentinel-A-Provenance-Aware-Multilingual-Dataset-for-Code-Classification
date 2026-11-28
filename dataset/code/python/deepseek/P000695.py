Here is the Python code for the problem:

def first_occurrence(nums, target):
    def helper(left, right):
        if right - left <= 1:
            if nums[left] == target:
                return left
            else:
                return -1

        mid = (left + right) // 2
        if nums[mid] < target:
            return helper(mid, right)
        elif nums[mid] > target:
            return helper(left, mid)
        else:
            if mid == 0 or nums[mid - 1] < target:
                return mid
            else:
                return helper(left, mid)

    return helper(0, len(nums))


nums = [1, 3, 3, 4, 4, 6, 10, 10, 10, 13]
target = 10
print(first_occurrence(nums, target))  

In this code, the `first_occurrence` function takes a sorted list of integers and a target integer as input. It then calls a helper function to perform a binary search on the list. The helper function checks if the middle element of the list is less than the target, in which case it calls itself recursively with the right half of the list. If the middle element is greater than the target, it calls itself recursively with the left half of the list. If the middle element is equal to the target, it checks whether the previous element is less than the target. If it is, it returns the index of the first occurrence. Otherwise, it returns the index of the current element. If the right index - left index is less than or equal to 1, it checks if the left or right element is the target and returns the index.