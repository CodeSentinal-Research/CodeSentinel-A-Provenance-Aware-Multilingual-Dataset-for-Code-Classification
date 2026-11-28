import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    left = 0
    zeros = 0
    max_len = 0
    
    for right in range(n):
        if nums[right] == 0:
            zeros += 1
        while zeros > 1:
            if nums[left] == 0:
                zeros -= 1
            left += 1
        max_len = max(max_len, right - left + 1)
        
    # Since we must delete one element, the result is max_len - 1 if max_len > 0
    # But if all are 1s, we must delete one 1, so length is n-1.
    # The sliding window finds longest subarray with at most 1 zero.
    # Deleting that zero gives a sequence of 1s.
    
    if max_len == n:
        print(n - 1)
    else:
        print(max_len - 1 if max_len > 0 else 0)

solve()

