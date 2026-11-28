import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    seen = set()
    for num in nums:
        if num in seen:
            print("YES")
            return
        seen.add(num)
    print("NO")

solve()

