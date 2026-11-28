from typing import List

def count_windows_containing_zero(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    zeros = sum(1 for x in nums[:k] if x == 0)
    ans = 1 if zeros > 0 else 0

    for i in range(k, len(nums)):
        zeros += (nums[i] == 0) - (nums[i - k] == 0)
        if zeros > 0:
            ans += 1

    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_windows_containing_zero(nums, k))