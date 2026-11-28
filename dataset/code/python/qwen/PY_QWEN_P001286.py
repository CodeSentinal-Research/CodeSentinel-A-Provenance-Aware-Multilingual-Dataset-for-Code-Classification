import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    additional_rocks = int(input_data[idx]); idx += 1
    capacity = list(map(int, input_data[idx:idx+n])); idx += n
    rocks = list(map(int, input_data[idx:idx+n])); idx += n
    
    diffs = [capacity[i] - rocks[i] for i in range(n)]
    diffs.sort()
    
    count = 0
    for diff in diffs:
        if additional_rocks >= diff:
            additional_rocks -= diff
            count += 1
        else:
            break
            
    print(count)

if __name__ == "__main__":
    solve()

