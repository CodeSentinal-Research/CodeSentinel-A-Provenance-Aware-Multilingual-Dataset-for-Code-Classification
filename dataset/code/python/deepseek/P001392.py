def count_subarrays(N, K, arr):
    count = 0
    prefix_sum = [0] * (N + 1)
    prefix_sum[0] = 0
    for i in range(1, N + 1):
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1]

    for start in range(N):
        for end in range(start, N):
            if prefix_sum[end + 1] - prefix_sum[start] % K == 0:
                count += 1
    return count

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_subarrays(N, K, arr))

if __name__ == "__main__":
    main()