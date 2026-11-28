import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    coins = int(input_data[idx]); idx += 1
    costs = list(map(int, input_data[idx:idx+n]))
    
    costs.sort()
    count = 0
    
    for cost in costs:
        if coins >= cost:
            coins -= cost
            count += 1
        else:
            break
            
    print(count)

if __name__ == "__main__":
    solve()

