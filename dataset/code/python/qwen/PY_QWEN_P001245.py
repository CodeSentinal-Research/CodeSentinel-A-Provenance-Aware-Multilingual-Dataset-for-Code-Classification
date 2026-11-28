import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    people = []
    for _ in range(n):
        h = int(input_data[idx]); idx += 1
        k = int(input_data[idx]); idx += 1
        people.append((h, k))
        
    people.sort(key=lambda x: (-x[0], x[1]))
    
    queue = []
    for h, k in people:
        queue.insert(k, h)
        
    print(*queue)

if __name__ == "__main__":
    solve()

