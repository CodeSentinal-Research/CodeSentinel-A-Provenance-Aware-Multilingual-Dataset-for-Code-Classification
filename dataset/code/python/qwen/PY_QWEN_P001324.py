import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    k = int(input_data[0])
    n = int(input_data[1])
    
    results = []
    
    def backtrack(start, current_sum, path):
        if len(path) == k:
            if current_sum == n:
                results.append(path[:])
            return
        if current_sum > n:
            return
            
        for i in range(start, 10):
            path.append(i)
            backtrack(i + 1, current_sum + i, path)
            path.pop()
            
    backtrack(1, 0, [])
    for res in results:
        print(" ".join(map(str, res)))

if __name__ == "__main__":
    solve()

