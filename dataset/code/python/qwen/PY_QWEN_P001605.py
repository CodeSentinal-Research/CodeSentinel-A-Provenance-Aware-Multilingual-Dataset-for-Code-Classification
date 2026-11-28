import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    prefix_map = {0: -1}
    current_sum = 0
    max_len = 0
    
    for i in range(n):
        current_sum += nums[i]
        if (current_sum - k) in prefix_map:
            max_len = max(max_len, i - prefix_map[current_sum - k])
        if current_sum not in prefix_map:
            prefix_map[current_sum] = i
            
    print(max_len)

solve()

