from typing import List

def count_increasing_windows(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    non_inc = sum(1 for i in range(k - 1) if nums[i] >= nums[i + 1])
    ans = 1 if non_inc == 0 else 0

    for i in range(k, len(nums)):
        non_inc += (nums[i - 1] >= nums[i]) - (nums[i - k] >= nums[i - k + 1])
        if non_inc == 0:
            ans += 1

    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_increasing_windows(nums, k))