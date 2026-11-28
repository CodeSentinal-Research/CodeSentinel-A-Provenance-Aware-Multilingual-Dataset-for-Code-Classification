import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    total_sum = sum(nums)
    if total_sum % k != 0:
        print("NO")
        return
        
    target = total_sum // k
    nums.sort(reverse=True)
    subsets = [0] * k
    
    def backtrack(index):
        if index == n:
            return True
        for i in range(k):
            if subsets[i] + nums[index] <= target:
                subsets[i] += nums[index]
                if backtrack(index + 1):
                    return True
                subsets[i] -= nums[index]
            if subsets[i] == 0:
                break
        return False
        
    print("YES" if backtrack(0) else "NO")

if __name__ == "__main__":
    solve()

