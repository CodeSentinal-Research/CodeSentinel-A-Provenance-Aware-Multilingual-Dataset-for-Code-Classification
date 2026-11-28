import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    count = 0
    current_sum = 0
    for num in nums:
        current_sum += num
        if current_sum % k == 0:
            count += 1
            
    print(count)

solve()

