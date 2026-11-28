Here is the Python code for the problem:

def merge_sort(nums, start, end):
    if start >= end:
        return 0

    mid = (start + end) // 2
    inv = merge_sort(nums, start, mid) + merge_sort(nums, mid + 1, end)

    p1 = start
    p2 = mid + 1
    p3 = end
    temp = [0] * (end - start + 1)

    while p1 <= mid and p2 <= end:
        if nums[p1] <= nums[p2]:
            temp[p3 - start] = nums[p1]
            p1 += 1
        else:
            temp[p3 - start] = nums[p2]
            inv += mid - p1 + 1
            p2 += 1
        p3 += 1

    while p1 <= mid:
        temp[p3 - start] = nums[p1]
        p1 += 1
        p3 += 1
    while p2 <= end:
        temp[p3 - start] = nums[p2]
        p2 += 1
        p3 += 1

    nums[start:end + 1] = temp
    return inv

def count_inversions(nums):
    return merge_sort(nums, 0, len(nums) - 1)

The `merge_sort` function implements the recursive Merge Sort approach. It uses a divide-and-conquer strategy to sort the array. The function `count_inversions` calls `merge_sort` with the initial array and its start and end indices. The recursion stops when the start index is greater than the end index.

In the `merge_sort` function, it uses three pointers `p1`, `p2`, and `p3` to traverse the arrays `nums`. It maintains a temporary array `temp` to store the sorted elements. The number of inversions is maintained in a variable `inv`.

The while loops in `merge_sort` function compare the elements at pointers `p1` and `p2` and adds the number of inversions in the right part to the total inversions `inv`.

The final while loops in `merge_sort` finally fill the original array `nums` with the sorted elements from `temp`. The total number of inversions is returned.

The `count_inversions` function just calls `merge_sort` with the initial array and its start and end indices.