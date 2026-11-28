Here is the Python code for the problem:

def max_sum_subarray(arr, k):
    n = len(arr)
    prefix_sum = [0]*(n+1)
    max_sum = 0
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + arr[i]
        if i >= k-1:
            max_sum = max(max_sum, prefix_sum[i+1]-prefix_sum[i-k+1])
    return max_sum

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(max_sum_subarray(arr, K))

if __name__ == "__main__":
    main()

This code first reads the input, then uses a prefix sum array to calculate the maximum possible sum for each subarray of length at most K. Finally, it returns the maximum possible total sum.