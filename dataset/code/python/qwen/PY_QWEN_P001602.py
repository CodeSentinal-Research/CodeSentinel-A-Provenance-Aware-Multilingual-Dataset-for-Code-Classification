import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    max_abs = 0
    current_sum = 0
    for num in nums:
        current_sum += num
        max_abs = max(max_abs, abs(current_sum))
        
    print(max_abs)

solve()

