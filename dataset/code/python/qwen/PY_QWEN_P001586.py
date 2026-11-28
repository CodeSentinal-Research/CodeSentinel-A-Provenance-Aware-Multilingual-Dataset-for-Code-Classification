import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    carpet_len = int(input_data[idx]); idx += 1
    
    tiles = []
    for _ in range(n):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        tiles.append((start, end))
        
    tiles.sort()
    
    max_covered = 0
    left = 0
    current_covered = 0
    
    # Prefix sum of tile lengths
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + (tiles[i][1] - tiles[i][0] + 1)
        
    for right in range(n):
        # Carpet ends at tiles[right][1]
        carpet_start = tiles[right][1] - carpet_len + 1
        
        # Find leftmost tile that overlaps with carpet
        while left < right and tiles[left][1] < carpet_start:
            left += 1
            
        # Calculate covered
        covered = 0
        for i in range(left, right + 1):
            t_start = tiles[i][0]
            t_end = tiles[i][1]
            
            intersect_start = max(t_start, carpet_start)
            intersect_end = min(t_end, tiles[right][1])
            
            if intersect_start <= intersect_end:
                covered += intersect_end - intersect_start + 1
                
        max_covered = max(max_covered, covered)
        
    print(max_covered)

solve()

