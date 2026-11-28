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
    
    if n % 2 != 0:
        print("NO")
        return
        
    remainder_counts = Counter([x % k for x in nums])
    
    for r in range(k):
        if r == 0:
            if remainder_counts[r] % 2 != 0:
                print("NO")
                return
        elif 2 * r == k:
            if remainder_counts[r] % 2 != 0:
                print("NO")
                return
        else:
            if remainder_counts[r] != remainder_counts[k - r]:
                print("NO")
                return
                
    print("YES")

solve()

