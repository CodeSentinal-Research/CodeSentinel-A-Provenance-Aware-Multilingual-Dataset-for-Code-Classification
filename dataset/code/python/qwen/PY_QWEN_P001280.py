import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    m = int(input_data[idx]); idx += 1
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+m]))
    
    patches = 0
    miss = 1
    i = 0
    
    while miss <= n:
        if i < m and nums[i] <= miss:
            miss += nums[i]
            i += 1
        else:
            miss += miss
            patches += 1
            
    print(patches)

if __name__ == "__main__":
    solve()

