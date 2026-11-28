import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    limit = int(input_data[idx]); idx += 1
    weights = list(map(int, input_data[idx:idx+n]))
    
    weights.sort()
    left = 0
    right = n - 1
    boats = 0
    
    while left <= right:
        if left == right:
            boats += 1
            break
        if weights[left] + weights[right] <= limit:
            left += 1
            right -= 1
        else:
            right -= 1
        boats += 1
        
    print(boats)

solve()

