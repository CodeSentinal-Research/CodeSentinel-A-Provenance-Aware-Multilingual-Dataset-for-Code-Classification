from typing import List

class Job:
    def __init__(self, id, deadline, profit):
        self.id = id
        self.deadline = deadline
        self.profit = profit

class Solution:
    def JobScheduling(self, jobs: List[Job], n: int) -> List[int]:
        jobs.sort(key=lambda j: j.profit, reverse=True)
        max_d = max(j.deadline for j in jobs)
        slot = [-1] * (max_d + 1)

        count = 0
        total_profit = 0

        for j in jobs:
            for d in range(j.deadline, 0, -1):
                if slot[d] == -1:
                    slot[d] = j.id
                    count += 1
                    total_profit += j.profit
                    break

        return [count, total_profit]