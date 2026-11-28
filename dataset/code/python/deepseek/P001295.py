Here is a Python solution that uses the prefix sum approach.

def solve():
    N, K = map(int, input().split())
    weights = list(map(int, input().split()))

    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i + 1] = prefix_sum[i] + weights[i]

    result = float('inf')
    for i in range(K):
        for j in range(i, N, K):
            result = min(result, prefix_sum[j] - prefix_sum[i])

    return result

print(solve())

This code first reads the input, then it calculates the prefix sum of the weights. It then iterates over all possible start points for the contiguous subarrays of size `K`. For each start point, it calculates the sum of the weights in the subarray from the start point to `i`. The difference between the maximum and minimum sum is then stored in the result variable. The final result is the minimum difference.