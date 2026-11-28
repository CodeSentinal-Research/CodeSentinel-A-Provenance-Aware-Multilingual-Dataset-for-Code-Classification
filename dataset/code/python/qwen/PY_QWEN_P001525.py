import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    # Transform: even -> 1, odd -> -1? No.
    # Even/Odd balance.
    # Prefix sum of (+1 if even, -1 if odd).
    # Find longest subarray with sum 0.
    
    prefix_map = {0: -1}
    current_sum = 0
    max_len = 0
    
    for i in range(n):
        if nums[i] % 2 == 0:
            current_sum += 1
        else:
            current_sum -= 1
            
        if current_sum in prefix_map:
            max_len = max(max_len, i - prefix_map[current_sum])
        else:
            prefix_map[current_sum] = i
            
    print(max_len)

solve()

