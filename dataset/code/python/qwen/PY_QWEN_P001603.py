import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    x = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    current_sum = 0
    for i in range(n):
        current_sum += nums[i]
        if current_sum >= x:
            print(i + 1)
            return
            
    print(-1)

solve()

