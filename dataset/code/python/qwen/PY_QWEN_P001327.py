import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    nums.sort()
    results = []
    
    def backtrack(start, path):
        results.append(path[:])
        for i in range(start, n):
            if i > start and nums[i] == nums[i-1]:
                continue
            path.append(nums[i])
            backtrack(i + 1, path)
            path.pop()
            
    backtrack(0, [])
    for res in results:
        print(" ".join(map(str, res)) if res else "")

if __name__ == "__main__":
    solve()

