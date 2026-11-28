from typing import List

def count_even_sum_windows(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    cur_sum = sum(nums[:k])
    ans = 1 if cur_sum % 2 == 0 else 0

    for i in range(k, len(nums)):
        cur_sum += nums[i] - nums[i - k]
        if cur_sum % 2 == 0:
            ans += 1

    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_even_sum_windows(nums, k))