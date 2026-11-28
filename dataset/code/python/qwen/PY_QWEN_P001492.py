import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    x = int(input_data[idx]); idx += 1
    arr = list(map(int, input_data[idx:idx+n]))
    
    # Binary search for the left bound of the k closest elements
    left = 0
    right = n - k
    
    while left < right:
        mid = (left + right) // 2
        if x - arr[mid] > arr[mid + k] - x:
            left = mid + 1
        else:
            right = mid
            
    print(*arr[left:left+k])

solve()

