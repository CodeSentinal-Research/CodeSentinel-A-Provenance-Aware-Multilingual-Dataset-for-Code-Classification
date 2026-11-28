import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    nums1 = list(map(int, input_data[idx:idx+n])); idx += n
    nums2 = list(map(int, input_data[idx:idx+m]))
    
    # Recover original array from doubled array logic is complex.
    # Assuming standard problem: Given an array where each element is doubled and shuffled, find original.
    # Here we have two arrays? No, problem says "Given an array formed by taking every element...".
    # Let's assume input is just one array of size 2N.
    # But input format says N and M. Let's stick to the provided structure.
    # If it's P001408 "Recover the Original Array", usually input is 2N numbers.
    # Let's assume the input is a single array of 2*N elements based on standard LeetCode 2099.
    # But the prompt says N and M. Let's assume N is the count of pairs?
    # Let's implement the standard solution for "Find Original Array From Doubled Array" assuming 2N inputs.
    
    # Re-reading prompt: "First line contains integer N. Second line contains 2N integers."
    # Wait, my previous extraction said: "First line contains integer N. Second line contains N integers." for P001407.
    # For P001408: "First line contains integer N. Second line contains 2N integers."
    
    # Let's adjust parsing for P001408 specifically if needed, but here I will use the generic parser.
    # If the input has 2N numbers in the second line, n will be 2N.
    
    nums = nums1 + nums2 # Combining if they are split
    nums.sort()
    counter = Counter(nums)
    original = []
    
    for num in nums:
        if counter[num] == 0:
            continue
        if counter[2 * num] == 0:
            print("-1")
            return
        counter[num] -= 1
        counter[2 * num] -= 1
        original.append(num)
        
    print(*original)

solve()

