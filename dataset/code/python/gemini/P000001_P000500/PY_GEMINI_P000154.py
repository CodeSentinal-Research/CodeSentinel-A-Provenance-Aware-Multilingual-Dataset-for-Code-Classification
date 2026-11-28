from typing import List

class Solution:
    def findTwoElement(self, arr: List[int]) -> List[int]:
        n = len(arr)
        repeating = missing = -1

        for i in range(n):
            val = abs(arr[i])
            if arr[val - 1] < 0:
                repeating = val
            else:
                arr[val - 1] = -arr[val - 1]

        for i in range(n):
            if arr[i] > 0:
                missing = i + 1
                break

        return [repeating, missing]