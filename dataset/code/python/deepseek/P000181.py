def max_sum_subarrays(arr, L, M):
    n = len(arr)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + arr[i]

    max_sum = float('-inf')
    for i in range(L, n + 1):
        max_sum = max(max_sum, prefix_sum[i] - prefix_sum[i - L])

    max_sum2 = float('-inf')
    for i in range(L + M, n + 1):
        max_sum2 = max(max_sum2, prefix_sum[i] - prefix_sum[i - L])

    return max(max_sum, max_sum2)

def main():
    N, L, M = map(int, input().split())
    arr = list(map(int, input().split()))
    print(max_sum_subarrays(arr, L, M))

if __name__ == "__main__":
    main()