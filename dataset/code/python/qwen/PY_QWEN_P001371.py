import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    target = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    num_to_index = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_to_index:
            print(num_to_index[complement], i)
            return
        num_to_index[num] = i
    print(-1)

solve()

