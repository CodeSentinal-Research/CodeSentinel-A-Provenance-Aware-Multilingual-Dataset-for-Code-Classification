# problem title : Course Schedule III
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        pq = []
        time = 0

        for duration, last_day in courses:
            time += duration
            heapq.heappush(pq, -duration)
            if time > last_day:
                time += heapq.heappop(pq)

        return len(pq)
