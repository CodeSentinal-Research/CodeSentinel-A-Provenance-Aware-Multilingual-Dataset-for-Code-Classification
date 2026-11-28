# problem title : Heap Sort
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def heapify(arr: List[int], n: int, i: int):
            largest = i
            l = 2 * i + 1
            r = 2 * i + 2
            if l < n and arr[l] > arr[largest]: largest = l
            if r < n and arr[r] > arr[largest]: largest = r
            if largest != i:
                arr[i], arr[largest] = arr[largest], arr[i]
                heapify(arr, n, largest)

        n = len(nums)
        for i in range(n // 2 - 1, -1, -1):
            heapify(nums, n, i)
        for i in range(n - 1, 0, -1):
            nums[i], nums[0] = nums[0], nums[i]
            heapify(nums, i, 0)
        return nums
