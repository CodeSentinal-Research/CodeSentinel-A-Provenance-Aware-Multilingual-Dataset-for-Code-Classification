import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    transformed = [1 if x == 1 else -1 for x in nums]
    
    prefix_map = {0: -1}
    current_sum = 0
    max_len = 0
    
    for i in range(n):
        current_sum += transformed[i]
        if current_sum in prefix_map:
            max_len = max(max_len, i - prefix_map[current_sum])
        else:
            prefix_map[current_sum] = i
            
    print(max_len)

solve()

