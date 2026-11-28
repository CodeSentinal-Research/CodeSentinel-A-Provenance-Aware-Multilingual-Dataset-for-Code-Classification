import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    budget = int(input_data[idx]); idx += 1
    charge_times = list(map(int, input_data[idx:idx+n])); idx += n
    running_costs = list(map(int, input_data[idx:idx+n]))
    
    left = 0
    sum_running = 0
    max_charge = 0
    dq = deque()
    max_robots = 0
    
    for right in range(n):
        sum_running += running_costs[right]
        while dq and charge_times[dq[-1]] <= charge_times[right]:
            dq.pop()
        dq.append(right)
        max_charge = charge_times[dq[0]]
        
        while left <= right and max_charge + (right - left + 1) * sum_running > budget:
            sum_running -= running_costs[left]
            if dq[0] == left:
                dq.popleft()
            left += 1
            if dq:
                max_charge = charge_times[dq[0]]
            else:
                max_charge = 0
                
        max_robots = max(max_robots, right - left + 1)
        
    print(max_robots)

solve()

