import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    present = [False] * (n + 2)
    for num in nums:
        if 0 < num <= n:
            present[num] = True
            
    for i in range(1, n + 2):
        if not present[i]:
            print(i)
            return

solve()

