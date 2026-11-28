import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    num_set = set(nums)
    max_len = 0
    
    for num in num_set:
        if num - 1 not in num_set:
            current_num = num
            current_len = 1
            
            while current_num + 1 in num_set:
                current_num += 1
                current_len += 1
                
            max_len = max(max_len, current_len)
            
    print(max_len)

solve()

