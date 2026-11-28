import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    product_counts = Counter()
    tuples = 0
    
    for i in range(n):
        for j in range(i + 1, n):
            prod = nums[i] * nums[j]
            if prod in product_counts:
                tuples += product_counts[prod]
            product_counts[prod] += 1
            
    print(tuples * 8) # Each pair (a,b) and (c,d) can form 8 permutations

solve()

