def find_floor(nums, target):
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    target = int(input().strip())
    result = find_floor(nums, target)
    print(result)

if __name__ == '__main__':
    main()