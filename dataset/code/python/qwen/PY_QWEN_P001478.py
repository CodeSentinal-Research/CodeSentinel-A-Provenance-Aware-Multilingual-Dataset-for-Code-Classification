import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    intervals1 = []
    for _ in range(n):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        intervals1.append((start, end))
        
    intervals2 = []
    for _ in range(m):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        intervals2.append((start, end))
        
    i, j = 0, 0
    intersections = []
    
    while i < n and j < m:
        start = max(intervals1[i][0], intervals2[j][0])
        end = min(intervals1[i][1], intervals2[j][1])
        
        if start <= end:
            intersections.append((start, end))
            
        if intervals1[i][1] < intervals2[j][1]:
            i += 1
        else:
            j += 1
            
    for start, end in intersections:
        print(start, end)

solve()

