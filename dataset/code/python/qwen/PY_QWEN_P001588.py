import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    # AtMost(K) - AtMost(K-1)
    def at_most_k(target):
        left = 0
        count = 0
        odd_count = 0
        for right in range(n):
            if nums[right] % 2 != 0:
                odd_count += 1
            while odd_count > target:
                if nums[left] % 2 != 0:
                    odd_count -= 1
                left += 1
            count += right - left + 1
        return count
        
    print(at_most_k(k) - at_most_k(k - 1))

solve()

