import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    in_degree = [0] * (n+1)
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        in_degree[v] += 1
        
    count = sum(1 for i in range(1, n+1) if in_degree[i] == 0)
    print(count)

if __name__ == "__main__":
    solve()

