from typing import List

def range_xor(nums: List[int], l: int, r: int) -> int:
    ans = 0
    for x in nums[l:r + 1]:
        ans ^= x
    return ans

if __name__ == '__main__':
    n, l, r = map(int, input().split())
    nums = list(map(int, input().split()))
    print(range_xor(nums, l, r))