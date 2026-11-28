import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    min_len = float('inf')
    
    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += nums[j]
            if current_sum > 0:
                min_len = min(min_len, j - i + 1)
                break
                
    print(min_len if min_len != float('inf') else 0)

solve()

