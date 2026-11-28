import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    constraints = []
    for _ in range(m):
        # Parse constraints based on specific format
        pass
        
    # Placeholder for complex matrix filling
    print("IMPOSSIBLE")

if __name__ == "__main__":
    solve()

