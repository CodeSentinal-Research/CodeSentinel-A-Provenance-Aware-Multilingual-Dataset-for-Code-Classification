Here's a Python solution using binary search, which has a time complexity of O(log n).

def singleNonDuplicate(nums):
    left, right = 0, len(nums) - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] == nums[mid ^ 1]:
            left = mid + 1
        else:
            right = mid
    return nums[left]

This function works by using binary search to find the single element. The `mid` variable represents the middle index of the current search space. If the element at `mid` is the same as the element at `mid^1` (the element on the right of `mid`, if `mid` is even), we know that the single element must be on the right side of `mid`, so we update `left` to `mid + 1`. Otherwise, we update `right` to `mid`. This binary search ensures that the time complexity is O(log n).

The `^` operator is a bitwise XOR operator, which returns 1 if the two bits are different, and 0 if they are the same. We use it to find the element that is different from the element at `mid^1`.

In the main function, we handle the input.

def main():
    nums = list(map(int, input().split()))[1:]
    print(singleNonDuplicate(nums))

main()

This code reads an array of integers from the input, removes the first element (as it's always the single element), and then calls the `singleNonDuplicate` function with this array. The result is printed out.