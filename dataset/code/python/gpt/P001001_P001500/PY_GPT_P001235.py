# problem title : Job Sequencing with Deadlines
# Solve the stated task using standard input and standard output.
from typing import List

def job_sequencing(deadlines: List[int], profits: List[int]) -> List[int]:
    jobs = sorted(zip(deadlines, profits), key=lambda x: x[1], reverse=True)
    max_d = max(deadlines)
    slots = [-1] * (max_d + 1)
    count = 0
    total_profit = 0

    for d, p in jobs:
        for j in range(d, 0, -1):
            if slots[j] == -1:
                slots[j] = p
                count += 1
                total_profit += p
                break

    return [count, total_profit]

if __name__ == '__main__':
    n = int(input())
    deadlines = list(map(int, input().split()))
    profits = list(map(int, input().split()))
    ans = job_sequencing(deadlines, profits)
    print(ans[0], ans[1])
