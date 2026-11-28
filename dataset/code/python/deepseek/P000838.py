Here's the Python code for the given problem:

def findMedianSortedArrays(nums1, nums2):
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1

    x, y = len(nums1), len(nums2)
    low, high = 0, x

    while low <= high:
        mid = (low + high) // 2
        mid2 = (x + y - mid) // 2

        maxLeft1 = float('-inf') if mid == 0 else nums1[mid - 1]
        minRight1 = float('inf') if mid == x else nums1[mid]

        maxLeft2 = float('-inf') if mid2 == 0 else nums2[mid2 - 1]
        minRight2 = float('inf') if mid2 == y else nums2[mid2]

        if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
            if (x + y) % 2 == 0:
                return max(maxLeft1, maxLeft2) + min(minRight1, minRight2) / 2.0
            else:
                return max(maxLeft1, maxLeft2)

        elif maxLeft1 > minRight2:
            high = mid - 1

        else:
            low = mid + 1

print(findMedianSortedArrays([1, 3], [2]))

This code first checks if `nums1` is the larger array. If it is, it swaps the two arrays. Then it uses binary search to find the median of the two arrays. The time complexity is O(log(min(m, n))).

In the main function, you can input two arrays like this:

if __name__ == "__main__":
    print(findMedianSortedArrays([1, 3], [2]))

In the code above, we call the function with two arrays as input. The output will be the median of the combined sorted array.