def binary_search(nums, target):
    def search(left, right):
        if right < left:
            return -1
        mid = left + (right - left) // 2
        if nums[mid] == target:
            return mid
        if nums[mid] > target:
            return search(left, mid - 1)
        return search(mid + 1, right)
    return search(0, len(nums) - 1)

def main():
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    target = 6
    result = binary_search(nums, target)
    print(result)

if __name__ == "__main__":
    main()