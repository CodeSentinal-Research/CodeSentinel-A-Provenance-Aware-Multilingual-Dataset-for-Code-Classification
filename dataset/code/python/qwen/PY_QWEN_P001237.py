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
        intervals.append((start, end))
        
    intervals.sort(key=lambda x: x[1])
    
    count = 0
    last_end = -float('inf')
    
    for start, end in intervals:
        if start >= last_end:
            last_end = end
        else:
            count += 1
            
    print(count)

if __name__ == "__main__":
    solve()

