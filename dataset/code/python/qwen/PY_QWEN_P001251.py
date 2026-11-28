import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    truck_size = int(input_data[idx]); idx += 1
    
    boxes = []
    for _ in range(n):
        count = int(input_data[idx]); idx += 1
        units = int(input_data[idx]); idx += 1
        boxes.append((units, count))
        
    boxes.sort(reverse=True)
    
    total_units = 0
    remaining_size = truck_size
    
    for units, count in boxes:
        if remaining_size == 0:
            break
        take = min(count, remaining_size)
        total_units += take * units
        remaining_size -= take
        
    print(total_units)

if __name__ == "__main__":
    solve()

