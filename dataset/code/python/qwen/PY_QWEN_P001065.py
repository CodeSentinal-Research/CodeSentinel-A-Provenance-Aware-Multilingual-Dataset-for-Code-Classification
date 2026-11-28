import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    total_edges = 0
    for _ in range(n):
        line = sys.stdin.readline().split()
        if line:
            k = int(line[0])
            total_edges += k
            
    # Undirected graph, each edge counted twice in adjacency list
    print(total_edges // 2)

if __name__ == "__main__":
    solve()

