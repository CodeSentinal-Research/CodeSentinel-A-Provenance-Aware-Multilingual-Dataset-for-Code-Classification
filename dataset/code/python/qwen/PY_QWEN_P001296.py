import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    plant_time = list(map(int, input_data[idx:idx+n])); idx += n
    grow_time = list(map(int, input_data[idx:idx+n])); idx += n
    
    seeds = sorted(zip(grow_time, plant_time), reverse=True)
    
    current_time = 0
    max_bloom = 0
    
    for grow, plant in seeds:
        current_time += plant
        max_bloom = max(max_bloom, current_time + grow)
        
    print(max_bloom)

if __name__ == "__main__":
    solve()

