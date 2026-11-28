from typing import List

def max_product_window(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    cur_prod = 1
    for x in nums[:k]:
        cur_prod *= x
    max_prod = cur_prod

    for i in range(k, len(nums)):
        cur_prod = (cur_prod // nums[i - k]) * nums[i]
        max_prod = max(max_prod, cur_prod)

    return max_prod

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_product_window(nums, k))