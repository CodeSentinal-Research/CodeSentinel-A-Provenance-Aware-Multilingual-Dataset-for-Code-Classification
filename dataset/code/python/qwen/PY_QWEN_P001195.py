import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    even = 0
    odd = 0
    
    for num in nums:
        even, odd = max(even, odd + num), max(odd, even - num)
        
    print(max(even, odd))

if __name__ == "__main__":
    solve()

