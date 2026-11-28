import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    weights = list(map(int, input_data[idx:idx+n])); idx += n
    capacities = list(map(int, input_data[idx:idx+m])); idx += m
    
    weights.sort()
    capacities.sort()
    
    boats = 0
    w_ptr = 0
    c_ptr = 0
    
    while w_ptr < n and c_ptr < m:
        if weights[w_ptr] <= capacities[c_ptr]:
            w_ptr += 1
        c_ptr += 1
        boats += 1
        
    if w_ptr < n:
        print(-1)
    else:
        print(boats)

if __name__ == "__main__":
    solve()

