import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    q = int(input_data[idx]); idx += 1
    
    freq_map = defaultdict(int)
    group_map = defaultdict(list) # stack of values for each frequency
    max_freq = 0
    output = []
    
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "PUSH":
            val = int(input_data[idx]); idx += 1
            freq_map[val] += 1
            f = freq_map[val]
            max_freq = max(max_freq, f)
            group_map[f].append(val)
        elif op == "POP":
            val = group_map[max_freq].pop()
            freq_map[val] -= 1
            if not group_map[max_freq]:
                max_freq -= 1
            output.append(str(val))
            
    print("
".join(output))

if __name__ == "__main__":
    solve()

