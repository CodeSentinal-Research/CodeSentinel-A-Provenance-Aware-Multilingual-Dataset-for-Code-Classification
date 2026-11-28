Here is the Python code for the given problem:

def smallest_subarray_sum():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    smallest_sum = float('inf')
    current_sum = 0
    
    for i in range(n):
        current_sum += arr[i]
        if current_sum < smallest_sum:
            smallest_sum = current_sum
        if current_sum > 0:
            current_sum = 0
    
    return smallest_sum if smallest_sum != float('inf') else None

print(smallest_subarray_sum())

In this code, we read the array size and array elements from the input. We then initialize `smallest_sum` as a large number (infinity) and `current_sum` as 0. We then iterate over the array and update `current_sum` accordingly. If `current_sum` is less than `smallest_sum`, we update `smallest_sum`. If `current_sum` is greater than 0, we reset it to 0. Finally, we return `smallest_sum` if it's not equal to infinity, otherwise, return None.