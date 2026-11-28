import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    nums.sort()
    min_diff = float('inf')
    
    for i in range(1, n):
        diff = nums[i] - nums[i-1]
        if diff < min_diff:
            min_diff = diff
            
    pairs = []
    for i in range(1, n):
        if nums[i] - nums[i-1] == min_diff:
            pairs.append((nums[i-1], nums[i]))
            
    for a, b in pairs:
        print(a, b)

if __name__ == "__main__":
    solve()

