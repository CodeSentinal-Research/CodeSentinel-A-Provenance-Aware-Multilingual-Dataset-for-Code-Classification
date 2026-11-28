from typing import List

def first_missing_positive(nums: List[int]) -> int:
    num_set = set(nums)
    i = 1
    while i in num_set:
        i += 1
    return i

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(first_missing_positive(nums))