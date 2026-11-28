import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    costs = []
    for _ in range(2 * n):
        a = int(input_data[idx]); idx += 1
        b = int(input_data[idx]); idx += 1
        costs.append((a - b, a, b))
        
    costs.sort()
    
    total_cost = 0
    for i in range(2 * n):
        if i < n:
            total_cost += costs[i][1] # Send to A
        else:
            total_cost += costs[i][2] # Send to B
            
    print(total_cost)

if __name__ == "__main__":
    solve()

