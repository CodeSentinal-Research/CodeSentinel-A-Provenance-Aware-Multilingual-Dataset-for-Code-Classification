import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    val = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    k = 0
    for i in range(n):
        if nums[i] != val:
            nums[k] = nums[i]
            k += 1
            
    print(k)
    print(*nums[:k])

solve()

