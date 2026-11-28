import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    
    results = []
    
    def backtrack(start, path):
        if len(path) == k:
            results.append(path[:])
            return
        for i in range(start, n + 1):
            path.append(i)
            backtrack(i + 1, path)
            path.pop()
            
    backtrack(1, [])
    for res in results:
        print(" ".join(map(str, res)))

if __name__ == "__main__":
    solve()

