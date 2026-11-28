import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    if n % k != 0:
        print("NO")
        return
        
    counter = Counter(nums)
    nums.sort()
    
    for num in nums:
        if counter[num] == 0:
            continue
        for i in range(k):
            if counter[num + i] == 0:
                print("NO")
                return
            counter[num + i] -= 1
            
    print("YES")

if __name__ == "__main__":
    solve()

