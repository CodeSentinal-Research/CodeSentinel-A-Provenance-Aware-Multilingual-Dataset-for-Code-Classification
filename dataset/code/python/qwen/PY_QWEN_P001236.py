import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    balloons = []
    for _ in range(n):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        balloons.append((end, start))
        
    balloons.sort()
    
    arrows = 0
    last_arrow_pos = -float('inf')
    
    for end, start in balloons:
        if start > last_arrow_pos:
            arrows += 1
            last_arrow_pos = end
            
    print(arrows)

if __name__ == "__main__":
    solve()

