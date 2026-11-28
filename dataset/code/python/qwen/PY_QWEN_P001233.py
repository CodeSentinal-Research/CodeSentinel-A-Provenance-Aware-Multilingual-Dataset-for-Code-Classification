import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    w = int(input_data[idx]); idx += 1
    
    items = []
    for _ in range(n):
        weight = int(input_data[idx]); idx += 1
        value = int(input_data[idx]); idx += 1
        items.append((value / weight, weight, value))
        
    items.sort(reverse=True)
    
    total_value = 0.0
    remaining_w = w
    
    for ratio, weight, value in items:
        if remaining_w == 0:
            break
        take = min(weight, remaining_w)
        total_value += take * ratio
        remaining_w -= take
        
    print("{:.2f}".format(total_value))

if __name__ == "__main__":
    solve()

