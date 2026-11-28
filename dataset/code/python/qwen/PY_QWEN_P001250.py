import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    counter = Counter(nums)
    ends = Counter()
    
    for num in nums:
        if ends[num - 1] > 0:
            ends[num - 1] -= 1
            ends[num] += 1
        elif counter[num + 1] > 0 and counter[num + 2] > 0:
            counter[num + 1] -= 1
            counter[num + 2] -= 1
            ends[num + 2] += 1
        else:
            print("NO")
            return
            
    print("YES")

if __name__ == "__main__":
    solve()

