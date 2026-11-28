import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    gas = list(map(int, input_data[idx:idx+n])); idx += n
    cost = list(map(int, input_data[idx:idx+n])); idx += n
    
    total_tank = 0
    curr_tank = 0
    start_station = 0
    
    for i in range(n):
        total_tank += gas[i] - cost[i]
        curr_tank += gas[i] - cost[i]
        if curr_tank < 0:
            start_station = i + 1
            curr_tank = 0
            
    if total_tank >= 0:
        print(start_station)
    else:
        print(-1)

if __name__ == "__main__":
    solve()

