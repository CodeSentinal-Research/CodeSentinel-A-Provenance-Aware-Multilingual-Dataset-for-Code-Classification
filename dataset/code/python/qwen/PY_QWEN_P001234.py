import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    arrivals = []
    departures = []
    
    for _ in range(n):
        arr = int(input_data[idx]); idx += 1
        dep = int(input_data[idx]); idx += 1
        arrivals.append(arr)
        departures.append(dep)
        
    arrivals.sort()
    departures.sort()
    
    platforms = 1
    max_platforms = 1
    i = 1
    j = 0
    
    while i < n and j < n:
        if arrivals[i] <= departures[j]:
            platforms += 1
            i += 1
        else:
            platforms -= 1
            j += 1
        max_platforms = max(max_platforms, platforms)
        
    print(max_platforms)

if __name__ == "__main__":
    solve()

