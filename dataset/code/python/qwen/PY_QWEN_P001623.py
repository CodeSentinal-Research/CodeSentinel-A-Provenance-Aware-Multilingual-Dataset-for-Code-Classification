import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    count = 0
    current_sum = 0
    for num in nums:
        current_sum += num
        if current_sum < 0:
            count += 1
            
    print(count)

solve()

