import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    first_line = input_data[0].split()
    n = int(first_line[0])
    m = int(first_line[1])
    target = int(first_line[2])
    
    matrix = []
    for i in range(1, n + 1):
        matrix.append(list(map(int, input_data[i].split())))
        
    count = 0
    
    for r1 in range(n):
        col_sums = [0] * m
        for r2 in range(r1, n):
            for c in range(m):
                col_sums[c] += matrix[r2][c]
                
            # Count subarrays in col_sums with sum == target
            prefix_sum = 0
            counter = Counter()
            counter[0] = 1
            for s in col_sums:
                prefix_sum += s
                if (prefix_sum - target) in counter:
                    count += counter[prefix_sum - target]
                counter[prefix_sum] += 1
                
    print(count)

solve()

