def count_pivot_indices(N, A):
    prefix_sum = [0] * N
    suffix_sum = [0] * N

    prefix_sum[0] = A[0]
    for i in range(1, N):
        prefix_sum[i] = prefix_sum[i - 1] + A[i]

    total_sum = sum(A)

    for i in range(N - 1, -1, -1):
        suffix_sum[i] = suffix_sum[i + 1] + A[i]

    pivot_count = 0

    for i in range(N):
        if i == 0 or i == N - 1:
            continue
        if prefix_sum[i - 1] == suffix_sum[i + 1]:
            pivot_count += 1

    print(pivot_count)

N = int(input().strip())
A = list(map(int, input().strip().split()))

count_pivot_indices(N, A)