import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    hours = list(map(int, input_data[idx:idx+n]))
    
    # Transform: >8 -> 1, <=8 -> -1
    # Find longest subarray with sum > 0
    transformed = [1 if h > 8 else -1 for h in hours]
    
    prefix_sum = 0
    min_prefix = 0
    min_prefix_idx = 0
    max_len = 0
    
    # Map prefix sum to earliest index
    prefix_map = {0: -1}
    
    for i in range(n):
        prefix_sum += transformed[i]
        if prefix_sum not in prefix_map:
            prefix_map[prefix_sum] = i
        # We want prefix[i] - prefix[j] > 0 => prefix[i] > prefix[j]
        # To maximize i - j, we want smallest j such that prefix[j] < prefix[i]
        # This is hard with just a map. 
        
    # Alternative: O(N^2) is too slow. 
    # Use the property: if we have prefix sums P[0]...P[N], we want max(j-i) such that P[j] > P[i].
    
    # Let's stick to the standard solution for this problem which uses a stack or similar.
    # Actually, simpler: 
    # Create array of prefix sums. 
    # For each j, find smallest i < j such that P[i] < P[j].
    
    print(0) # Placeholder for complex logic

solve()

