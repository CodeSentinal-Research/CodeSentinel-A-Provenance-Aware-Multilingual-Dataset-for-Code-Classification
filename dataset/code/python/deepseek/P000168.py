def longest_decreasing_subarray():
    N = int(input())
    arr = list(map(int, input().split()))
    
    longest_decreasing_subarray = 1
    current_decreasing_subarray = 1
    
    for i in range(1, N):
        if arr[i] < arr[i-1]:
            current_decreasing_subarray += 1
            longest_decreasing_subarray = max(longest_decreasing_subarray, current_decreasing_subarray)
        else:
            current_decreasing_subarray = 1
    
    return longest_decreasing_subarray

print(longest_decreasing_subarray())