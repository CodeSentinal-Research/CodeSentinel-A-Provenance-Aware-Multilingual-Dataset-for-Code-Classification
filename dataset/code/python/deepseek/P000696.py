def last_occurrence(nums, target):
    def binary_search(left, right):
        if right - left <= 1:
            return right if nums[right] == target else -1

        mid = left + (right - left) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            return binary_search(left, mid)
        else:
            return binary_search(mid, right)

    return binary_search(0, len(nums) - 1)

def main():
    nums = list(map(int, input().split()))
    target = nums.pop()
    print(last_occurrence(nums, target))

if __name__ == "__main__":
    main()