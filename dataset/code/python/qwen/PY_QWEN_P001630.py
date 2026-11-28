import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    a = list(map(int, input_data[idx:idx+n])); idx += n
    b = list(map(int, input_data[idx:idx+n]))
    
    ops = 0
    diff_sum = 0
    
    for i in range(n):
        diff_sum += a[i] - b[i]
        if diff_sum < 0:
            ops += -diff_sum
            diff_sum = 0
            
    print(ops)

solve()

