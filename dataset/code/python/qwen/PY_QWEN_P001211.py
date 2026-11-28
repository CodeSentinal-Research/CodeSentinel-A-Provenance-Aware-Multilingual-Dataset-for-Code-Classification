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
    visited = [False] * n
    
    def backtrack(index, current_sum, count):
        if count == k - 1:
            return True
        if current_sum == target:
            return backtrack(0, 0, count + 1)
            
        for i in range(index, n):
            if not visited[i] and current_sum + nums[i] <= target:
                visited[i] = True
                if backtrack(i + 1, current_sum + nums[i], count):
                    return True
                visited[i] = False
                if current_sum == 0:
                    break
        return False
        
    print("YES" if backtrack(0, 0, 0) else "NO")

if __name__ == "__main__":
    solve()

