def shortest_prefix_with_sum_greater_than_x():
    N, X = map(int, input().split())
    A = list(map(int, input().split()))

    prefix_sum = [0] * (N + 1)
    prefix_sum[0] = A[0]
    for i in range(1, N):
        prefix_sum[i] = prefix_sum[i - 1] + A[i]

    min_len = float('inf')
    for i in range(N):
        for j in range(i, N):
            if prefix_sum[j] - (prefix_sum[i - 1] if i > 0 else 0) > X:
                min_len = min(min_len, j - i + 1)

    if min_len == float('inf'):
        print(-1)
    else:
        print(min_len)

shortest_prefix_with_sum_greater_than_x()