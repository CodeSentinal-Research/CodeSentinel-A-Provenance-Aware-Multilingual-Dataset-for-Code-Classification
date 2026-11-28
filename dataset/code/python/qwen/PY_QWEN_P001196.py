import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    count = 0
    curr = 0
    
    for i in range(2, n):
        if nums[i] - nums[i-1] == nums[i-1] - nums[i-2]:
            curr += 1
            count += curr
        else:
            curr = 0
            
    print(count)

if __name__ == "__main__":
    solve()

