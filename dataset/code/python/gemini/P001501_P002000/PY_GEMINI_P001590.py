from typing import List
from collections import deque

class Solution:
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        dq = deque()
        l = 0
        sum_cost = 0

        for r in range(len(chargeTimes)):
            sum_cost += runningCosts[r]
            while dq and chargeTimes[dq[-1]] <= chargeTimes[r]:
                dq.pop()
            dq.append(r)

            while l <= r and chargeTimes[dq[0]] + (r - l + 1) * sum_cost > budget:
                if dq[0] == l:
                    dq.popleft()
                sum_cost -= runningCosts[l]
                l += 1

        return len(chargeTimes) - l