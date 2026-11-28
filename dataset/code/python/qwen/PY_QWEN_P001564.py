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
    
    # Using two heaps to maintain median of sliding window
    # This is complex to implement efficiently in O(N log K). 
    # For simplicity and correctness within constraints, we might use a sorted list approach or balanced BST simulation.
    # Given Python's lack of built-in ordered multiset, we'll use a simplified approach or bisect.
    
    from bisect import insort, bisect_left
    
    window = []
    results = []
    
    for i in range(n):
        insort(window, nums[i])
        if i >= k:
            window.remove(nums[i-k])
            
        if i >= k - 1:
            mid = k // 2
            if k % 2 == 1:
                results.append(str(window[mid]))
            else:
                val = (window[mid-1] + window[mid]) / 2
                if val == int(val):
                    results.append(str(int(val)))
                else:
                    results.append("{:.1f}".format(val))
                    
    print(" ".join(results))

solve()

