import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    if n < 10:
        return
        
    seen = set()
    result = []
    
    for i in range(n - 9):
        sub = s[i:i+10]
        if sub in seen:
            if sub not in result: # Avoid duplicates in output
                result.append(sub)
        else:
            seen.add(sub)
            
    for r in sorted(result):
        print(r)

solve()

