import sys
import bisect

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    success = int(input_data[idx]); idx += 1
    
    spells = list(map(int, input_data[idx:idx+n])); idx += n
    potions = list(map(int, input_data[idx:idx+m]))
    
    potions.sort()
    
    results = []
    for spell in spells:
        # Need spell * potion >= success => potion >= success / spell
        target = success / spell
        idx_pot = bisect.bisect_left(potions, target)
        results.append(m - idx_pot)
        
    print(*results)

solve()

