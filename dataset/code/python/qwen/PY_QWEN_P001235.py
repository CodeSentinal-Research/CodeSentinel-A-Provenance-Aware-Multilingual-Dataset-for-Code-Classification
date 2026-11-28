import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    jobs = []
    max_deadline = 0
    for _ in range(n):
        d = int(input_data[idx]); idx += 1
        p = int(input_data[idx]); idx += 1
        jobs.append((p, d))
        max_deadline = max(max_deadline, d)
        
    jobs.sort(reverse=True)
    
    slot = [-1] * (max_deadline + 1)
    total_profit = 0
    
    for profit, deadline in jobs:
        for j in range(min(deadline, max_deadline), 0, -1):
            if slot[j] == -1:
                slot[j] = profit
                total_profit += profit
                break
                
    print(total_profit)

if __name__ == "__main__":
    solve()

