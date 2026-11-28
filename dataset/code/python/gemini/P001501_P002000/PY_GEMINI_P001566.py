from typing import List
from collections import deque

def min_sliding_window(nums: List[int], k: int) -> List[int]:
    dq = deque()
    res = []

    for i, x in enumerate(nums):
        while dq and nums[dq[-1]] >= x:
            dq.pop()
        dq.append(i)

        while dq[0] <= i - k:
            dq.popleft()

        if i >= k - 1:
            res.append(nums[dq[0]])

    return res

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(*min_sliding_window(nums, k))