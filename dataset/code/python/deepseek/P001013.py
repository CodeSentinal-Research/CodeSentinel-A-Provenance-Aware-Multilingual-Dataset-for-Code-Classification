Here is the Python code for the problem.

import sys
import heapq

def running_median(nums):
    lower_half = []  
    upper_half = []  

    for num in nums:
        if not lower_half or num > lower_half[0]:
            heapq.heappush(lower_half, num)
        else:
            heapq.heappush(upper_half, -num)

        if len(lower_half) > len(upper_half) + 1:
            heappush = heapq.heappush
            heappush(upper_half, -heappop(lower_half))
        elif len(upper_half) > len(lower_half):
            heappush = heapq.heappush
            heappush(lower_half, -heappop(upper_half))

        if len(lower_half) == len(upper_half):
            median = (-lower_half[0] + upper_half[0]) / 2
        else:
            median = -lower_half[0]
        print(median)

if __name__ == '__main__':
    N = int(sys.stdin.readline().strip())
    nums = list(map(int, sys.stdin.readline().strip().split()))
    running_median(nums)

This program uses two heaps to calculate the median. One max heap is used to store the lower half of the numbers, and one min heap is used to store the upper half. The median is calculated by taking the root of the max heap (which is the largest number in the lower half) and the root of the min heap (which is the smallest number in the upper half). If the sizes of the two heaps are equal, the median is the average of the roots. This ensures that all numbers from the stream are processed in sorted order and the median is always the middle number.