import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    changed = list(map(int, input_data[idx:idx+n]))
    
    changed.sort()
    counter = Counter(changed)
    original = []
    
    for num in changed:
        if counter[num] > 0:
            if counter[2 * num] > 0:
                original.append(num)
                counter[num] -= 1
                counter[2 * num] -= 1
            else:
                print("-1")
                return
                
    print(*original)

solve()

