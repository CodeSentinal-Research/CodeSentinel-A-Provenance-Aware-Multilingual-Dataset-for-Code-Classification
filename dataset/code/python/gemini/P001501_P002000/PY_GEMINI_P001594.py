from typing import List

def build_prefix_sum(nums: List[int]) -> List[int]:
    prefix = []
    cur = 0
    for x in nums:
        cur += x
        prefix.append(cur)
    return prefix

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(*build_prefix_sum(nums))