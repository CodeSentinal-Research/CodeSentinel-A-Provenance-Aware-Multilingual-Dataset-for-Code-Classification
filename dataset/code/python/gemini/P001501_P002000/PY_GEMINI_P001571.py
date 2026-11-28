from typing import List

def max_diff_first_last(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    return max(abs(nums[i + k - 1] - nums[i]) for i in range(len(nums) - k + 1))

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_diff_first_last(nums, k))