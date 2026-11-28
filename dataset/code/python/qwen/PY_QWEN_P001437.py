import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    num_set = set(nums)
    for num in nums:
        if 2 * num in num_set and num != 0:
            print("YES")
            return
        if num == 0 and nums.count(0) > 1:
            print("YES")
            return
            
    print("NO")

solve()

