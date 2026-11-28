from typing import List

def max_odds_in_window(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    cur_odds = sum(1 for x in nums[:k] if x % 2 != 0)
    max_odds = cur_odds

    for i in range(k, len(nums)):
        cur_odds += (nums[i] % 2 != 0) - (nums[i - k] % 2 != 0)
        max_odds = max(max_odds, cur_odds)

    return max_odds

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_odds_in_window(nums, k))