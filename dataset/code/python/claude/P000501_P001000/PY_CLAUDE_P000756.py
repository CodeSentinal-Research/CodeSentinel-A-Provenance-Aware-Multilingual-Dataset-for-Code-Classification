
from typing import List

class Solution:
    def quickSort(self, arr: List[int]) -> List[int]:
        self._qs(arr, 0, len(arr) - 1)
        return arr

    def _qs(self, arr, lo, hi):
        if lo < hi:
            pi = self._partition(arr, lo, hi)
            self._qs(arr, lo, pi - 1)
            self._qs(arr, pi + 1, hi)

    def _partition(self, arr, lo, hi):
        pivot = arr[hi]
        i = lo - 1
        for j in range(lo, hi):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[hi] = arr[hi], arr[i + 1]
        return i + 1
