def findUnsortedSubarray(nums):
    sorted_nums = sorted(nums)
    start, end = -1, -1

    for i in range(len(nums)):
        if nums[i] != sorted_nums[i]:
            if start == -1:
                start = i
            end = i

    if start == -1:
        return 0
    else:
        return end - start + 1
This code creates a new list of sorted numbers and then compares the original list with the sorted list to find the unsorted subarray. The start and end index of the unsorted subarray are updated as we go through the original list.