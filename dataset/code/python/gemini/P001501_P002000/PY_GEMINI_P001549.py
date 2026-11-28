from typing import List

def count_all_positive_windows(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    non_pos = sum(1 for x in nums[:k] if x <= 0)
    ans = 1 if non_pos == 0 else 0

    for i in range(k, len(nums)):
        non_pos += (nums[i] <= 0) - (nums[i - k] <= 0)
        if non_pos == 0:
            ans += 1

    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_all_positive_windows(nums, k))