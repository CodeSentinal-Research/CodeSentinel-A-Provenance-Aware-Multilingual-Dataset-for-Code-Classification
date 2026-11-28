import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    total_sum = sum(nums)
    if total_sum % 3 != 0:
        print(0)
        return
        
    target = total_sum // 3
    prefix_sum = 0
    count_ways = 0
    ways_to_split_first = 0
    
    for i in range(n - 1):
        prefix_sum += nums[i]
        if prefix_sum == 2 * target:
            count_ways += ways_to_split_first
        if prefix_sum == target:
            ways_to_split_first += 1
            
    print(count_ways)

solve()

