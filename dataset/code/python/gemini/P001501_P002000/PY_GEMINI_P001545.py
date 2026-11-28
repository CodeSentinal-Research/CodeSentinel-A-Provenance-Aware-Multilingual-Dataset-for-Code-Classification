from typing import List
from collections import deque

def min_max_min_diff_window(nums: List[int], k: int) -> int:
    max_dq, min_dq = deque(), deque()
    min_diff = float('inf')

    for i, x in enumerate(nums):
        while max_dq and nums[max_dq[-1]] <= x:
            max_dq.pop()
        while min_dq and nums[min_dq[-1]] >= x:
            min_dq.pop()
        max_dq.append(i)
        min_dq.append(i)

        while max_dq[0] <= i - k:
            max_dq.popleft()
        while min_dq[0] <= i - k:
            min_dq.popleft()

        if i >= k - 1:
            min_diff = min(min_diff, nums[max_dq[0]] - nums[min_dq[0]])

    return min_diff

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(min_max_min_diff_window(nums, k))