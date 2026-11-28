import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    results = []
    
    def backtrack(start, path):
        if len(path) == k:
            results.append(path[:])
            return
        for i in range(start, n):
            if not path or nums[i] > path[-1]:
                path.append(nums[i])
                backtrack(i + 1, path)
                path.pop()
                
    backtrack(0, [])
    for res in results:
        print(" ".join(map(str, res)))

if __name__ == "__main__":
    solve()

