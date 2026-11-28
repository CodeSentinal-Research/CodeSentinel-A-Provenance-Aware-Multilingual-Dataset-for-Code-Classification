from typing import List

def count_prefixes_divisible_by_k(nums: List[int], k: int) -> int:
    cur = ans = 0
    for x in nums:
        cur += x
        if cur % k == 0:
            ans += 1
    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_prefixes_divisible_by_k(nums, k))