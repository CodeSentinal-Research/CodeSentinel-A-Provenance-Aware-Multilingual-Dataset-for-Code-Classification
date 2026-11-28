from typing import List

class Solution:
    def maxSumIS(self, arr: List[int], n: int) -> int:
        msis = list(arr)
        for i in range(1, n):
            for j in range(i):
                if arr[i] > arr[j] and msis[i] < msis[j] + arr[i]:
                    msis[i] = msis[j] + arr[i]
        return max(msis)