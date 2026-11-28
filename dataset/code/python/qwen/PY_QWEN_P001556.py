import sys
from collections import Counter

def solve():
    text = sys.stdin.readline().strip()
    pattern = sys.stdin.readline().strip()
    
    n = len(text)
    m = len(pattern)
    
    if m > n:
        print(0)
        return
        
    p_count = Counter(pattern)
    t_count = Counter(text[:m])
    
    matches = 0
    for char in p_count:
        if t_count[char] == p_count[char]:
            matches += 1
            
    count = 0
    if matches == len(p_count):
        count += 1
        
    for i in range(m, n):
        new_char = text[i]
        old_char = text[i-m]
        
        t_count[new_char] += 1
        if t_count[new_char] == p_count.get(new_char, 0):
            matches += 1
        elif t_count[new_char] == p_count.get(new_char, 0) + 1:
            matches -= 1
            
        t_count[old_char] -= 1
        if t_count[old_char] == p_count.get(old_char, 0):
            matches += 1
        elif t_count[old_char] == p_count.get(old_char, 0) - 1:
            matches -= 1
            
        if matches == len(p_count):
            count += 1
            
    print(count)

solve()

