import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    count_zeros = nums[:k].count(0)
    count = 1 if count_zeros > 0 else 0
    
    for i in range(k, n):
        if nums[i] == 0:
            count_zeros += 1
        if nums[i-k] == 0:
            count_zeros -= 1
        if count_zeros > 0:
            count += 1
            
    print(count)

solve()

