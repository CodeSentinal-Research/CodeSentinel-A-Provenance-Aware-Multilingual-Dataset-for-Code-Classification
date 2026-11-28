import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    dist = list(map(int, input_data[idx:idx+n])); idx += n
    speed = list(map(int, input_data[idx:idx+n])); idx += n
    
    time_to_reach = [d / s for d, s in zip(dist, speed)]
    time_to_reach.sort()
    
    killed = 0
    for t in time_to_reach:
        if killed < t:
            killed += 1
        else:
            break
            
    print(killed)

if __name__ == "__main__":
    solve()

