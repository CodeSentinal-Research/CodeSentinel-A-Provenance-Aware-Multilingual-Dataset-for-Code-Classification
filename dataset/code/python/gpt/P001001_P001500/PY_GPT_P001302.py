# problem title : Minimum Number of Meeting Rooms
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

def min_meeting_rooms(intervals: List[List[int]]) -> int:
    if not intervals:
        return 0
    intervals.sort(key=lambda x: x[0])
    pq = []

    for s, e in intervals:
        if pq and pq[0] <= s:
            heapq.heappop(pq)
        heapq.heappush(pq, e)

    return len(pq)

if __name__ == '__main__':
    n = int(input())
    intervals = [list(map(int, input().split())) for _ in range(n)]
    print(min_meeting_rooms(intervals))
