import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    top = list(map(int, input_data[idx:idx+n])); idx += n
    bottom = list(map(int, input_data[idx:idx+n])); idx += n
    
    for target in [top[0], bottom[0]]:
        rotations_top = 0
        rotations_bottom = 0
        possible = True
        
        for i in range(n):
            if top[i] != target and bottom[i] != target:
                possible = False
                break
            if top[i] != target:
                rotations_top += 1
            if bottom[i] != target:
                rotations_bottom += 1
                
        if possible:
            print(min(rotations_top, rotations_bottom))
            return
            
    print(-1)

if __name__ == "__main__":
    solve()

