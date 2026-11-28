Here is a Python solution for the problem. This solution uses the binary search and data structure, a tree map.

import sys
import bisect
from sortedcontainers import SortedDict

def main():
    N, CarpetLength = map(int, sys.stdin.readline().split())
    intervals = SortedDict()
    for i in range(N):
        start, end = map(int, sys.stdin.readline().split())
        if start not in intervals:
            intervals[start] = end
        else:
            intervals[start] = max(intervals[start], end)
    left, right = 0, CarpetLength
    while left < right:
        mid = (left + right + 1) // 2
        if is_possible(mid, intervals, CarpetLength):
            left = mid
        else:
            right = mid - 1
    print(left)

def is_possible(width, intervals, carpet_length):
    current = intervals.irange(0, width)
    for start, end in current:
        if end < width:
            continue
        current = current[end:]
        if len(current) == 0:
            return True
        current = current[1:]
    return False

if __name__ == "__main__":
    main()

In this code, we use a tree map to store the intervals of white tiles. The intervals are stored in sorted order, so we can use binary search to find the maximum width of the carpet that can be covered.

The `is_possible` function checks if it is possible to place a carpet of a certain width with the given intervals. It uses binary search to find a possible width and if it is possible, it updates the width.

The `main` function reads the input and calls `is_possible`. It uses binary search to find the maximum width that can be covered with the given intervals and the length of the carpet.