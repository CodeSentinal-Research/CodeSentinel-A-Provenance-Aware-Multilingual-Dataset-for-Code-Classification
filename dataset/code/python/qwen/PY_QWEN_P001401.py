import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    prefix_sum = 0
    count_map = {0: 1}
    max_len = 0
    
    for i in range(n):
        prefix_sum += nums[i]
        if (prefix_sum - k) in count_map:
            max_len = max(max_len, i - count_map[prefix_sum - k] + 1) # This logic is for count, not length. 
        # Correct approach for Longest Subarray with Sum K
        if prefix_sum not in count_map:
             count_map[prefix_sum] = i
            
    # Re-implementing correctly for Length
    prefix_indices = {}
    prefix_indices[0] = -1
    current_sum = 0
    max_len = 0
    
    for i in range(n):
        current_sum += nums[i]
        if (current_sum - k) in prefix_indices:
            max_len = max(max_len, i - prefix_indices[current_sum - k])
        if current_sum not in prefix_indices:
            prefix_indices[current_sum] = i
            
    print(max_len)

solve()

