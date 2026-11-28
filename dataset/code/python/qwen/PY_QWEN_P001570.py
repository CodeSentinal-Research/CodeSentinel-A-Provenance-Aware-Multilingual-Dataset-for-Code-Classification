import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    max_len = 0
    last_neg = -1
    first_neg = -1
    curr_len = 0
    
    for i in range(n):
        if nums[i] > 0:
            curr_len += 1
        elif nums[i] < 0:
            if first_neg == -1:
                first_neg = i
            last_neg = i
            curr_len = i - first_neg
        else:
            curr_len = 0
            last_neg = -1
            first_neg = -1
            
        if last_neg != -1:
             max_len = max(max_len, i - first_neg)
        else:
             if curr_len > 0:
                 max_len = max(max_len, curr_len)
                 
    # Correct logic for max length subarray with positive product
    # Keep track of first negative and last negative index in current segment without zeros
    
    pos_start = 0
    max_len = 0
    first_neg_idx = -1
    last_neg_idx = -1
    
    for i in range(n):
        if nums[i] == 0:
            pos_start = i + 1
            first_neg_idx = -1
            last_neg_idx = -1
            continue
            
        if nums[i] < 0:
            if first_neg_idx == -1:
                first_neg_idx = i
            last_neg_idx = i
            
        if nums[i] > 0:
            if last_neg_idx == -1:
                max_len = max(max_len, i - pos_start + 1)
            else:
                max_len = max(max_len, i - first_neg_idx)
        else: # negative
             if first_neg_idx != i: # if there was a previous negative
                 max_len = max(max_len, i - first_neg_idx)
                 
    print(max_len)

solve()

