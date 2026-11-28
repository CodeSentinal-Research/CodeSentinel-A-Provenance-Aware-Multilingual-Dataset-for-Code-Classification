def search(nums, target):
    def find_rotate_index(left, right):
        if nums[left] < nums[right]:
            return 0
        while left <= right:
            pivot = (left + right) // 2
            if nums[pivot] > nums[pivot + 1]:
                return pivot + 1
            else:
                if nums[pivot] < nums[left]:
                    right = pivot - 1
                else:
                    left = pivot + 1

    def search(left, right):
        while left <= right:
            pivot = (left + right) // 2
            if nums[pivot] == target:
                return True
            else:
                if nums[pivot] < target:
                    left = pivot + 1
                else:
                    right = pivot - 1
        return False

    n = len(nums)

    if n == 0:
        return False
    if n == 1:
        return nums[0] == target

    rotate_index = find_rotate_index(0, n - 1)

    if nums[rotate_index] == target:
        return True
    if rotate_index == 0:
        return False

    if target < nums[0]:
        return search(rotate_index, n - 1)
    return search(0, rotate_index)

def main():
    nums = [2, 5, 6, 0, 0, 1, 2]
    target = 0
    result = search(nums, target)
    print(result)

if __name__ == "__main__":
    main()