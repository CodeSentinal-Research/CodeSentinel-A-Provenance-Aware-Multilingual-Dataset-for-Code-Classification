from typing import List

class Solution:
    def findPlatform(self, arr: List[int], dep: List[int], n: int) -> int:
        arr.sort()
        dep.sort()

        platforms = max_platforms = 0
        i = j = 0

        while i < n and j < n:
            if arr[i] <= dep[j]:
                platforms += 1
                max_platforms = max(max_platforms, platforms)
                i += 1
            else:
                platforms -= 1
                j += 1

        return max_platforms