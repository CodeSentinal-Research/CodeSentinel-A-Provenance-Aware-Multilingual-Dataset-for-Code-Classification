def maxSumKSubarray():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    max_sum = curr_sum = sum(A[:K])

    for i in range(N - K):
        curr_sum = curr_sum - A[i] + A[i + K]
        max_sum = max(max_sum, curr_sum)

    print(max_sum)

maxSumKSubarray()