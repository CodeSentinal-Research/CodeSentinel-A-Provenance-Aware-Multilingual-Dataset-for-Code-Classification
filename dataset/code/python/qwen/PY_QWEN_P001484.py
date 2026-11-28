import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    max_len = 0
    i = 1
    while i < n:
        if nums[i] == nums[i-1]:
            i += 1
            continue
        up = True if nums[i] > nums[i-1] else False
        j = i
        while j < n and ((up and nums[j] > nums[j-1]) or (not up and nums[j] < nums[j-1])):
            j += 1
            up = not up
        length = j - (i - 1)
        if length > 2:
            max_len = max(max_len, length)
        i = j if j > i else i + 1
        
    print(max_len)

solve()

