import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    stack = []
    for num in nums:
        max_in_chunk = num
        while stack and stack[-1] > num:
            max_in_chunk = max(max_in_chunk, stack.pop())
        stack.append(max_in_chunk)
        
    print(len(stack))

solve()

