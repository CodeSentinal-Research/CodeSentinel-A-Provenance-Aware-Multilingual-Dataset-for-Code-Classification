import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    nums.sort()
    
    for i in range(n):
        if k == 0:
            break
        if nums[i] < 0:
            nums[i] = -nums[i]
            k -= 1
        elif nums[i] == 0:
            k = 0
            break
            
    if k % 2 == 1:
        min_val = min(nums)
        nums[nums.index(min_val)] *= -1
        
    print(sum(nums))

if __name__ == "__main__":
    solve()

