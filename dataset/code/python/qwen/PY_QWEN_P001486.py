import sys

def solve():
    v1 = sys.stdin.readline().strip()
    v2 = sys.stdin.readline().strip()
    
    parts1 = list(map(int, v1.split('.')))
    parts2 = list(map(int, v2.split('.')))
    
    len1 = len(parts1)
    len2 = len(parts2)
    max_len = max(len1, len2)
    
    for i in range(max_len):
        p1 = parts1[i] if i < len1 else 0
        p2 = parts2[i] if i < len2 else 0
        
        if p1 < p2:
            print(-1)
            return
        elif p1 > p2:
            print(1)
            return
            
    print(0)

solve()

