def min_sum_subarray(N, K, arr):
    window_sum = sum(arr[:K])
    min_sum = window_sum

    for i in range(K, N):
        window_sum = window_sum - arr[i - K] + arr[i]
        min_sum = min(min_sum, window_sum)

    return min_sum

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(min_sum_subarray(N, K, arr))

if __name__ == "__main__":
    main()