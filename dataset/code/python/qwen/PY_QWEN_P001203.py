import sys
import bisect

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    envelopes = []
    for _ in range(n):
        w = int(input_data[idx]); idx += 1
        h = int(input_data[idx]); idx += 1
        envelopes.append((w, h))
        
    # Sort by width ascending, height descending if widths are equal
    envelopes.sort(key=lambda x: (x[0], -x[1]))
    
    # Find LIS of heights
    tails = []
    for w, h in envelopes:
        pos = bisect.bisect_left(tails, h)
        if pos == len(tails):
            tails.append(h)
        else:
            tails[pos] = h
            
    print(len(tails))

if __name__ == "__main__":
    solve()

