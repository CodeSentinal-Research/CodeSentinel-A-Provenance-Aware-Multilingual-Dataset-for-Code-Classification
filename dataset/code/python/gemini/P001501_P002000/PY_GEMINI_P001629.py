from typing import List

def longest_negative_prefix(nums: List[int]) -> int:
    cur = 0
    longest = 0
    for i, x in enumerate(nums):
        cur += x
        if cur < 0:
            longest = i + 1
    return longest

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(longest_negative_prefix(nums))