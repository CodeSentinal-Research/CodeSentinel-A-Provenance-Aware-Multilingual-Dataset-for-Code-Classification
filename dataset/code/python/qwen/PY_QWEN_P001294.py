import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    nums.sort(reverse=True)
    
    prefix_sum = 0
    count = 0
    
    for num in nums:
        prefix_sum += num
        if prefix_sum > 0:
            count += 1
            
    print(count)

if __name__ == "__main__":
    solve()

