import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    g = list(map(int, input_data[idx:idx+n])); idx += n
    s = list(map(int, input_data[idx:idx+m])); idx += m
    
    g.sort()
    s.sort()
    
    i = 0
    j = 0
    count = 0
    
    while i < n and j < m:
        if g[i] <= s[j]:
            count += 1
            i += 1
            j += 1
        else:
            j += 1
            
    print(count)

if __name__ == "__main__":
    solve()

