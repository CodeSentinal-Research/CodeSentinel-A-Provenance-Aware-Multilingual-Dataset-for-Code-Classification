import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    nums.sort()
    used = [False] * n
    results = []
    
    def backtrack(path):
        if len(path) == n:
            results.append(path[:])
            return
        for i in range(n):
            if used[i]:
                continue
            if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
                continue
            used[i] = True
            path.append(nums[i])
            backtrack(path)
            path.pop()
            used[i] = False
            
    backtrack([])
    for res in results:
        print(" ".join(map(str, res)))

if __name__ == "__main__":
    solve()

