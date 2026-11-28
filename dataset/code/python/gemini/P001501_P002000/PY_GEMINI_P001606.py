from typing import List
from collections import defaultdict

def count_equal_zeros_ones(nums: List[int]) -> int:
    count = defaultdict(int)
    count[0] = 1
    cur_sum = ans = 0

    for x in nums:
        cur_sum += 1 if x == 1 else -1
        ans += count[cur_sum]
        count[cur_sum] += 1

    return ans

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(count_equal_zeros_ones(nums))