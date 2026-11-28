# problem title : Course Schedule Ordering
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        in_deg = [0] * numCourses
        for course, pre in prerequisites:
            adj[pre].append(course)
            in_deg[course] += 1

        q = deque([i for i in range(numCourses) if in_deg[i] == 0])
        order = []
        while q:
            u = q.popleft()
            order.append(u)
            for v in adj[u]:
                in_deg[v] -= 1
                if in_deg[v] == 0:
                    q.append(v)

        return order if len(order) == numCourses else []
