import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    if n < 2:
        print(n)
        return
        
    up = 1
    down = 1
    
    for i in range(1, n):
        if nums[i] > nums[i-1]:
            up = down + 1
        elif nums[i] < nums[i-1]:
            down = up + 1
            
    print(max(up, down))

if __name__ == "__main__":
    solve()

