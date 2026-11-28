def longest_subarray(N, K, arr):
    curr_sum = arr[0]
    max_len = 0

    start = 0
    end = 1

    while end < N:
        if curr_sum > K:
            curr_sum -= arr[start]
            start += 1
        elif curr_sum < K:
            curr_sum += arr[end]
            end += 1
        else:
            max_len = max(max_len, end - start + 1)
            start += 1
            end += 1

    return max_len


N = int(input().strip())
K = int(input().strip())
arr = list(map(int, input().strip().split()))

print(longest_subarray(N, K, arr))