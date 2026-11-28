Here is the Python code:

def count_windows_with_even_sum(N, K, arr):
    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i+1] = prefix_sum[i] + arr[i]

    count = 0

    for i in range(K-1, N):
        if (prefix_sum[i+1] - prefix_sum[i-K+1]) % 2 == 0:
            count += 1
    return count

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_windows_with_even_sum(N, K, arr))

if __name__ == "__main__":
    main()

This code first calculates the prefix sum of the input array and then iterates over the prefix sum array to count the number of contiguous subarrays of size K whose sum is even. The prefix sum array is created such that prefix_sum[i] represents the sum of elements from 0 to i-1 in the array. The prefix sum array is then used to calculate the sum of each contiguous subarray of size K and check if the sum is even. If it is, the count is increased.