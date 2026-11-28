import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    heapq.heapify(nums)
    
    for _ in range(k):
        min_val = heapq.heappop(nums)
        heapq.heappush(nums, min_val + 1)
        
    product = 1
    MOD = 10**9 + 7
    for num in nums:
        product = (product * num) % MOD
        
    print(product)

if __name__ == "__main__":
    solve()

