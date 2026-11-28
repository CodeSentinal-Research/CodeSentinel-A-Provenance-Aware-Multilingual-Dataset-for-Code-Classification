import sys

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
        
    max_area = 0
    
    for r1 in range(n):
        col_sums = [0] * m
        for r2 in range(r1, n):
            for c in range(m):
                col_sums[c] += matrix[r2][c]
                
            # Find largest rectangle in histogram with sum <= k
            # This is complex. Simplified: check all subarrays? O(M^2) per row pair. Total O(N^2 M^2).
            # N, M <= 300. 300^4 = 8.1 * 10^9. Too slow.
            # Use sliding window or prefix sum on col_sums?
            # Since values can be negative, sliding window doesn't work directly for sum <= k.
            # But problem says "Sum not exceeding K".
            # Standard solution for Max Rectangle Sum <= K uses BST or sorted prefix sums. O(M log M).
            # Total O(N^2 M log M). 300^2 * 300 * 8 ~ 2 * 10^8. Might be tight but acceptable in Py if optimized?
            # Let's use simple O(M^2) for safety in Python if N, M small.
            
            prefix_s = [0] * (m + 1)
            for j in range(m):
                prefix_s[j+1] = prefix_s[j] + col_sums[j]
                
            for c1 in range(m):
                for c2 in range(c1, m):
                    s = prefix_s[c2+1] - prefix_s[c1]
                    if s <= k:
                        area = (r2 - r1 + 1) * (c2 - c1 + 1)
                        max_area = max(max_area, area)
                        
    print(max_area)

solve()

