import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    count = 0
    curr_len = 1
    
    for i in range(1, n):
        if nums[i] != nums[i-1]:
            count += curr_len
            curr_len = 1
        else:
            curr_len += 1
    count += curr_len
    
    # Number of alternating subarrays is sum of lengths of maximal alternating runs?
    # No, number of subarrays in a run of length L is L*(L+1)/2?
    # No, "alternating" means 0,1,0,1...
    # If we have a maximal alternating subarray of length L, it contributes L*(L+1)/2 subarrays?
    # Yes, every subarray of an alternating array is alternating.
    
    total = 0
    curr_len = 1
    for i in range(1, n):
        if nums[i] != nums[i-1]:
            curr_len += 1
        else:
            total += curr_len * (curr_len + 1) // 2
            curr_len = 1
    total += curr_len * (curr_len + 1) // 2
    
    print(total)

solve()

