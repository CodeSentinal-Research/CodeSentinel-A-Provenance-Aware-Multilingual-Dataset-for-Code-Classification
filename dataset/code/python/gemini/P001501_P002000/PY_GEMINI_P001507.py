from typing import List

class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        ans = 1
        anchor = 0

        for i in range(1, n):
            c = (arr[i - 1] > arr[i]) - (arr[i - 1] < arr[i])
            if c == 0:
                anchor = i
            elif i == n - 1 or c * ((arr[i] > arr[i + 1]) - (arr[i] < arr[i + 1])) != -1:
                ans = max(ans, i - anchor + 1)
                anchor = i

        return ans