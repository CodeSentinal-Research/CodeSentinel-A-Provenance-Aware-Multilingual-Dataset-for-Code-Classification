import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    tasks = []
    for _ in range(n):
        actual = int(input_data[idx]); idx += 1
        minimum = int(input_data[idx]); idx += 1
        tasks.append((minimum, actual))
        
    tasks.sort(key=lambda x: x[0] - x[1], reverse=True)
    
    energy = 0
    min_initial = 0
    
    for minimum, actual in tasks:
        if energy < minimum:
            min_initial += minimum - energy
            energy = minimum
        energy -= actual
        
    print(min_initial)

if __name__ == "__main__":
    solve()

