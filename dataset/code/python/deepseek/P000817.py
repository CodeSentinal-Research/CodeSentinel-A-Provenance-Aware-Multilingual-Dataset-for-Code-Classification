Here is the Python code for the problem:

def search(nums, target):
    if not nums:
        return -1

    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            return mid

        if nums[mid] >= nums[left]:
            if target >= nums[left] and target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if target <= nums[right] and target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1

    return -1

And here is the main function for input handling:

def main():
    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 6
    print(search(nums, target))  

if __name__ == "__main__":
    main()

The code above works by performing binary search on the sorted rotated array. For each midpoint, it checks if the target is in the range of the left or right part of the array. Depending on the value of the target, it adjusts the boundaries of the search. If the target is not found, it returns -1. The time complexity is O(log n), where n is the length of the input array.