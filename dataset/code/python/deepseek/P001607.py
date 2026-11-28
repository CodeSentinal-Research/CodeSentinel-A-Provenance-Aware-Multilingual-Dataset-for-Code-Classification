def maxSubarray(arr):
    n = len(arr)

    prefix_sum = [0] * n
    prefix_sum[0] = arr[0]
    for i in range(1, n):
        prefix_sum[i] = prefix_sum[i-1] + arr[i]

    suffix_sum = [0] * n
    suffix_sum[n-1] = arr[n-1]
    for i in range(n-2, -1, -1):
        suffix_sum[i] = suffix_sum[i+1] + arr[i]

    max_diff = max(suffix_sum) - min(prefix_sum)

    max_length = max(max_diff, max(prefix_sum), n - prefix_sum.index(min(prefix_sum)))

    return max_length

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(maxSubarray(arr))

if __name__ == "__main__":
    main()