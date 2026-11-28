def find_median_sorted_arrays(nums1, nums2):
    merged = sorted(nums1 + nums2)
    length = len(merged)
    if length % 2 == 0:
        return (merged[length // 2 - 1] + merged[length // 2]) / 2
    else:
        return merged[length // 2]

def main():
    nums1 = list(map(int, input().split()))[1:]
    nums2 = list(map(int, input().split()))[1:]
    print(find_median_sorted_arrays(nums1, nums2))

if __name__ == '__main__':
    main()