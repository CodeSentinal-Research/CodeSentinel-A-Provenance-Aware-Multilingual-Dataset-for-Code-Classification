import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    ranges = list(map(int, input_data[idx:idx+n+1]))
    
    intervals = []
    for i in range(n + 1):
        start = max(0, i - ranges[i])
        end = min(n, i + ranges[i])
        intervals.append((start, end))
        
    intervals.sort()
    
    taps = 0
    current_end = 0
    next_end = 0
    i = 0
    
    while current_end < n:
        while i < len(intervals) and intervals[i][0] <= current_end:
            next_end = max(next_end, intervals[i][1])
            i += 1
        if next_end == current_end:
            print(-1)
            return
        current_end = next_end
        taps += 1
        
    print(taps)

if __name__ == "__main__":
    solve()

