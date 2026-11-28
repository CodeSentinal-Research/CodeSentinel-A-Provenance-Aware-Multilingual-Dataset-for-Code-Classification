from typing import List

def max_negatives_in_window(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    cur_negs = sum(1 for x in nums[:k] if x < 0)
    max_negs = cur_negs

    for i in range(k, len(nums)):
        cur_negs += (nums[i] < 0) - (nums[i - k] < 0)
        max_negs = max(max_negs, cur_negs)

    return max_negs

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_negatives_in_window(nums, k))