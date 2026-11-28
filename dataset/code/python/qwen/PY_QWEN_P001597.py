import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx].split())); idx += 1
    q = int(input_data[idx]); idx += 1
    
    # Prefix counts for each value? Too much memory if values are large.
    # Use offline queries or coordinate compression if needed.
    # Given constraints, let's assume values are manageable or use a different approach.
    # Standard approach: Coordinate compress and use BIT/Segment Tree for each value? No.
    # Just iterate for each query if Q is small? No, Q up to 10^5.
    
    # Use a dictionary of prefix sums for each unique number?
    # Unique numbers can be up to N. Total memory O(N^2) worst case.
    
    # Better: Process queries offline? Or just use simple iteration if N*Q is too big.
    # Let's use a map of lists of indices for each number.
    
    num_indices = defaultdict(list)
    for i, num in enumerate(nums):
        num_indices[num].append(i)
        
    import bisect
    
    output = []
    for i in range(q):
        parts = input_data[idx].split(); idx += 1
        l = int(parts[0])
        r = int(parts[1])
        x = int(parts[2])
        
        indices = num_indices[x]
        # Count indices in [l, r]
        left_idx = bisect.bisect_left(indices, l)
        right_idx = bisect.bisect_right(indices, r)
        output.append(str(right_idx - left_idx))
        
    print("\n".join(output))

solve()

