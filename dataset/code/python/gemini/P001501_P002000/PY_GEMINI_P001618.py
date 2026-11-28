from typing import List

def build_prefix_xor(nums: List[int]) -> List[int]:
    res = []
    cur = 0
    for x in nums:
        cur ^= x
        res.append(cur)
    return res

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(*build_prefix_xor(nums))