Here is the Python code:

def max_sum_subarray(N, K, arr):
    window_sum = sum(arr[:K])
    max_sum = window_sum
    
    for i in range(N - K):
        window_sum = window_sum - arr[i] + arr[i + K]
        max_sum = max(window_sum, max_sum)
    
    return max_sum

if __name__ == "__main__":
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(max_sum_subarray(N, K, arr))
This code reads the input and calls the `max_sum_subarray` function. The function calculates the sum of the first window of size K and iteratively calculates the sum of the remaining windows by subtracting the element leaving the window and adding the element entering the window. It keeps updating the maximum sum as it iterates through the array.