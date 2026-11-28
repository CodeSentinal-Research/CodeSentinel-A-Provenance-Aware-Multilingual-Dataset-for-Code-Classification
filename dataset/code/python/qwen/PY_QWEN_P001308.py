import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    w = int(input_data[idx]); idx += 1
    h = int(input_data[idx]); idx += 1
    n = int(input_data[idx]); idx += 1
    
    x_coords = [0, w]
    y_coords = [0, h]
    
    for _ in range(n):
        x = int(input_data[idx]); idx += 1
        y = int(input_data[idx]); idx += 1
        x_coords.append(x)
        y_coords.append(y)
        
    x_coords.sort()
    y_coords.sort()
    
    max_x_gap = 0
    for i in range(1, len(x_coords)):
        max_x_gap = max(max_x_gap, x_coords[i] - x_coords[i-1])
        
    max_y_gap = 0
    for i in range(1, len(y_coords)):
        max_y_gap = max(max_y_gap, y_coords[i] - y_coords[i-1])
        
    print(max_x_gap * max_y_gap)

if __name__ == "__main__":
    solve()

