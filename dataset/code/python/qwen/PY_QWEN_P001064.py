import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    q = int(input_data[idx]); idx += 1
    
    edges = set()
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        edges.add((u, v))
        
    output = []
    for _ in range(q):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        if (u, v) in edges:
            output.append("YES")
        else:
            output.append("NO")
            
    print("
".join(output))

if __name__ == "__main__":
    solve()

