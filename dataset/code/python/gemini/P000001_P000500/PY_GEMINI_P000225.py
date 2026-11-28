from typing import List

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        arr_pos = sorted(list(enumerate(nums)), key=lambda x: x[1])
        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i] or arr_pos[i][0] == i:
                continue

            cycle_size = 0
            j = i
            while not visited[j]:
                visited[j] = True
                j = arr_pos[j][0]
                cycle_size += 1

            if cycle_size > 0:
                swaps += cycle_size - 1

        return swaps