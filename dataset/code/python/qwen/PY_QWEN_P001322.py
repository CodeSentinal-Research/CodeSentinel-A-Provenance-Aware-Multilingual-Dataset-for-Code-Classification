import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    target = int(input_data[idx]); idx += 1
    candidates = list(map(int, input_data[idx:idx+n]))
    
    candidates.sort()
    results = []
    
    def backtrack(start, current_sum, path):
        if current_sum == target:
            results.append(path[:])
            return
        if current_sum > target:
            return
            
        for i in range(start, n):
            path.append(candidates[i])
            backtrack(i, current_sum + candidates[i], path)
            path.pop()
            
    backtrack(0, 0, [])
    for res in results:
        print(" ".join(map(str, res)))

if __name__ == "__main__":
    solve()

