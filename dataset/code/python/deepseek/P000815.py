def search_range(nums, target):
    first = -1
    last = -1

    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            first = mid
            right = mid - 1  
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    left, right = first, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            last = mid
            left = mid + 1  
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return [first, last]


def main():
    nums = list(map(int, input("Enter the sorted array nums: ").split()))
    target = int(input("Enter the target: "))

    print(search_range(nums, target))


if __name__ == "__main__":
    main()