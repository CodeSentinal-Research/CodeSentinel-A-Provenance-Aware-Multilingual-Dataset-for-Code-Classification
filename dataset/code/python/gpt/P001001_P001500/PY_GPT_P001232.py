# problem title : Activity Selection
# Solve the stated task using standard input and standard output.
from typing import List

def activity_selection(start: List[int], end: List[int]) -> int:
    activities = sorted(zip(end, start))
    count = 0
    last_end = -1

    for e, s in activities:
        if s >= last_end:
            count += 1
            last_end = e

    return count

if __name__ == '__main__':
    n = int(input())
    start = list(map(int, input().split()))
    end = list(map(int, input().split()))
    print(activity_selection(start, end))
