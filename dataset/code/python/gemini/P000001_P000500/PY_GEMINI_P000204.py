from typing import List

class Solution:
    def waveSort(self, arr: List[int]) -> None:
        """Sorts the input array into ordered sequence."""
        for i in range(0, len(arr) - 1, 2):
            if i > 0 and arr[i] < arr[i - 1]:
                arr[i], arr[i - 1] = arr[i - 1], arr[i]
            if i < len(arr) - 1 and arr[i] < arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]