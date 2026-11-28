import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    ones_indices = [i for i, x in enumerate(nums) if x == 1]
    m = len(ones_indices)
    
    if m < k:
        print(-1)
        return
        
    # Median approach for minimum moves
    min_swaps = float('inf')
    
    for i in range(m - k + 1):
        median_idx = i + k // 2
        median_val = ones_indices[median_idx]
        
        cost = 0
        for j in range(i, i + k):
            cost += abs(ones_indices[j] - median_val) - abs(j - median_idx)
            
        min_swaps = min(min_swaps, cost)
        
    print(min_swaps)

solve()

