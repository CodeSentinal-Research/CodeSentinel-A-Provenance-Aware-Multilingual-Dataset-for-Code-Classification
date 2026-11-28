def shortestSubarray(nums, k):
    N = len(nums)
    prefix_sum = [0] * (N + 1)
    min_len = float('inf')

    for i in range(1, N + 1):
        prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]
        if prefix_sum[i] >= k:
            min_len = min(min_len, i)

    for i in range(N - 1, -1, -1):
        if prefix_sum[i] >= k:
            min_len = min(min_len, N - i)

    return -1 if min_len == float('inf') else min_len

def main():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))
    print(shortestSubarray(nums, K))

if __name__ == "__main__":
    main()