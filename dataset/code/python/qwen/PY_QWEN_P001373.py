import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    seen = {}
    for i, num in enumerate(nums):
        if num in seen:
            if i - seen[num] <= k:
                print("YES")
                return
        seen[num] = i
    print("NO")

solve()

