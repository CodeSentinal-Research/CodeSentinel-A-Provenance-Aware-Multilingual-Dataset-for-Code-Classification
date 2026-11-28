import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    subsets = [0] * k
    nums.sort(reverse=True)
    
    def backtrack(index):
        if index == n:
            return max(subsets)
        min_max_sum = float('inf')
        for i in range(k):
            subsets[i] += nums[index]
            res = backtrack(index + 1)
            min_max_sum = min(min_max_sum, res)
            subsets[i] -= nums[index]
            if subsets[i] == 0:
                break
        return min_max_sum
        
    print(backtrack(0))

if __name__ == "__main__":
    solve()

