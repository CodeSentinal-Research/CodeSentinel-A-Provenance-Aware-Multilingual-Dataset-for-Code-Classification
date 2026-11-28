import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    prefix_sum = 0
    # Map remainder to earliest index
    remainder_map = {0: -1}
    
    for i in range(n):
        prefix_sum += nums[i]
        remainder = prefix_sum % k
        if remainder < 0:
            remainder += k
            
        if remainder in remainder_map:
            if i - remainder_map[remainder] >= 2:
                print("YES")
                return
        else:
            remainder_map[remainder] = i
            
    print("NO")

solve()

