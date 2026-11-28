Here is a Python solution for the problem:

def find_target(nums, target):
    if not nums:
        return -1

    pivot = find_pivot(nums, 0, len(nums) - 1)

    if nums[pivot] == target:
        return pivot
    if nums[0] <= target:
        return binary_search(nums, 0, pivot, target)
    return binary_search(nums, pivot + 1, len(nums) - 1, target)


def find_pivot(nums, low, high):
    if nums[low] < nums[high]:
        return 0
    while low <= high:
        mid = (low + high) // 2
        if nums[mid] > nums[mid + 1]:
            return mid
        else if nums[mid] < nums[mid - 1]:
            high = mid - 1
        else if nums[low] < nums[mid]:
            low = mid + 1
        else:
            low = mid
    return -1


def binary_search(nums, low, high, target):
    while low <= high:
        mid = (low + high) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def main():
    nums = list(map(int, input().split()))[1:]
    target = int(input())
    print(find_target(nums, target))


if __name__ == "__main__":
    main()

The code firstly takes the number of elements and the target from the user input, then it finds the pivot element in the array. If the pivot is at the start or end of the array, then we can use the linear search to find the target. Otherwise, we perform a binary search on the two halves of the array. If the target is found in one half, we perform the binary search in the other half.