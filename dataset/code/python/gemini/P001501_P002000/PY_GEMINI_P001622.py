from typing import List

def count_positive_prefixes(nums: List[int]) -> int:
    cur = ans = 0
    for x in nums:
        cur += x
        if cur > 0:
            ans += 1
    return ans

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(count_positive_prefixes(nums))