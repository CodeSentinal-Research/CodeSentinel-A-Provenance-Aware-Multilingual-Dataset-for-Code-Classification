import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    n = int(input_data[0])
    
    content_map = defaultdict(list)
    for i in range(1, n + 1):
        parts = input_data[i].split()
        path = parts[0]
        for part in parts[1:]:
            idx = part.index('(')
            content = part[idx+1:-1]
            file_name = part[:idx]
            full_path = path + "/" + file_name
            content_map[content].append(full_path)
            
    for group in content_map.values():
        if len(group) > 1:
            print(" ".join(group))

solve()

