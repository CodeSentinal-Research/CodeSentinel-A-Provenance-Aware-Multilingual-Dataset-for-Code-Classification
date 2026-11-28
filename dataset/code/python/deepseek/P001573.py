def count_windows(N, K, D):
    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i + 1] = prefix_sum[i] + nums[i] % D

    count = 0

    for i in range(K, N + 1):
        if prefix_sum[i] % D == 0:
            count += 1

    return count


if __name__ == "__main__":
    N, K, D = map(int, input().split())
    nums = list(map(int, input().split()))

    print(count_windows(N, K, D))