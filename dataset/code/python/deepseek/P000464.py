def find_closest():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    target = int(input().strip())

    left, right = 0, N - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid
    return nums[left]

print(find_closest())