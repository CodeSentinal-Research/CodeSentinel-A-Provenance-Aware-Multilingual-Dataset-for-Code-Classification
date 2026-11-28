import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    activities = []
    for _ in range(n):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        activities.append((end, start))
        
    activities.sort()
    
    count = 0
    last_end = -1
    
    for end, start in activities:
        if start >= last_end:
            count += 1
            last_end = end
            
    print(count)

if __name__ == "__main__":
    solve()

