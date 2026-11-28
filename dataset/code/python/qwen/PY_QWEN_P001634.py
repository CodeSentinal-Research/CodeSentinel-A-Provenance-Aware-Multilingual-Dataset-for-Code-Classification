import sys
import bisect

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    first_line = input_data[0].split()
    n = int(first_line[0])
    m = int(first_line[1])
    k = int(first_line[2])
    
    matrix = []
    for i in range(1, n + 1):
        matrix.append(list(map(int, input_data[i].split())))
        
    max_sum = float('-inf')
    
    for r1 in range(n):
        col_sums = [0] * m
        for r2 in range(r1, n):
            for c in range(m):
                col_sums[c] += matrix[r2][c]
                
            # Max subarray sum <= k
            prefix_s = [0] * (m + 1)
            for j in range(m):
                prefix_s[j+1] = prefix_s[j] + col_sums[j]
                
            sorted_prefixes = []
            for s in prefix_s:
                # Find smallest prefix_p such that s - prefix_p <= k => prefix_p >= s - k
                idx = bisect.bisect_left(sorted_prefixes, s - k)
                if idx < len(sorted_prefixes):
                    max_sum = max(max_sum, s - sorted_prefixes[idx])
                bisect.insort(sorted_prefixes, s)
                
    print(max_sum)

solve()

