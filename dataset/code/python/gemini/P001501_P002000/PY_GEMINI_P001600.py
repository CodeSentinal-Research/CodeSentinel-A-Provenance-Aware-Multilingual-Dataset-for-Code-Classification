from typing import List

def range_average(nums: List[int], l: int, r: int) -> float:
    return sum(nums[l:r + 1]) / (r - l + 1)

if __name__ == '__main__':
    n, l, r = map(int, input().split())
    nums = list(map(int, input().split()))
    print(f"{range_average(nums, l, r):.2f}")