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
    
    for right in range(n):
        current_covered += tiles[right][1] - tiles[right][0] + 1
        
        # Check overlap with previous tiles if any
        # This simple sum assumes no overlap between tiles in input? 
        # Problem says "list of white tile intervals". Usually disjoint.
        
        # Shrink window from left if carpet doesn't cover
        while left <= right and tiles[right][1] - tiles[left][0] + 1 > carpet_len:
            current_covered -= tiles[left][1] - tiles[left][0] + 1
            left += 1
            
        # Calculate actual covered
        # Carpet starts at tiles[left][0] ideally?
        # Carpet covers [start, start + carpet_len - 1]
        # We want to maximize intersection with union of tiles[left..right]
        
        # Simplified: Carpet covers [tiles[right][1] - carpet_len + 1, tiles[right][1]]
        carpet_start = tiles[right][1] - carpet_len + 1
        
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

