# PY_GPT_P001590 - Maximum Robots Within Budget
# Problem-specific verified implementation.
n, budget = map(int, input().split())
charge = list(map(int, input().split()))
run = list(map(int, input().split()))
from collections import deque
q = deque()
left = total = best = 0
for right in range(n):
    while q and charge[q[-1]] <= charge[right]:
        q.pop()
    q.append(right)
    total += run[right]
    while charge[q[0]] + (right - left + 1) * total > budget:
        if q[0] == left:
            q.popleft()
        total -= run[left]
        left += 1
    best = max(best, right - left + 1)
print(best)
