def findMedianSortedArrays(nums1, nums2):
    nums1.extend(nums2)
    nums1.sort()
    length = len(nums1)

    if length % 2 == 0:
        return (nums1[length // 2] + nums1[length // 2 - 1]) / 2
    else:
        return nums1[length // 2]

def main():
    N = int(input().strip())
    nums1 = list(map(int, input().strip().split()))
    nums2 = list(map(int, input().strip().split()))
    print(findMedianSortedArrays(nums1, nums2))

if __name__ == "__main__":
    main()