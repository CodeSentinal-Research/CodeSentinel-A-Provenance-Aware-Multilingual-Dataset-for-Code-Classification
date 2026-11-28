import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    intervals = []
    for _ in range(n):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        intervals.append([start, end])
        
    new_start = int(input_data[idx]); idx += 1
    new_end = int(input_data[idx]); idx += 1
    
    intervals.append([new_start, new_end])
    intervals.sort()
    
    merged = []
    for interval in intervals:
        if not merged or merged[-1][1] < interval[0]:
            merged.append(interval)
        else:
            merged[-1][1] = max(merged[-1][1], interval[1])
            
    for start, end in merged:
        print(start, end)

if __name__ == "__main__":
    solve()

