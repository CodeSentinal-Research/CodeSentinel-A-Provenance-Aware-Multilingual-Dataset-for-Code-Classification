import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    total_trips = int(input_data[idx]); idx += 1
    times = list(map(int, input_data[idx:idx+n]))
    
    low = 1
    high = min(times) * total_trips
    
    def can_complete(t):
        trips = 0
        for time in times:
            trips += t // time
            if trips >= total_trips:
                return True
        return False
        
    while low < high:
        mid = (low + high) // 2
        if can_complete(mid):
            high = mid
        else:
            low = mid + 1
            
    print(low)

if __name__ == "__main__":
    solve()

