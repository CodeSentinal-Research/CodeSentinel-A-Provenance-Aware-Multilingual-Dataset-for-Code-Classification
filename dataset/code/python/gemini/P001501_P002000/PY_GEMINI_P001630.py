from typing import List

def min_ops_equalize_prefix(nums: List[int]) -> int:
    # Baseline difference reduction
    return sum(abs(nums[i] - nums[i - 1]) for i in range(1, len(nums)))

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(min_ops_equalize_prefix(nums))