def longest_subarray(N, K, A):
    prefix_sum = [0] * (N+1)
    max_length = 0
    for i in range(N):
        prefix_sum[i+1] = prefix_sum[i] + A[i]
        if prefix_sum[i+1] - K in prefix_sum:
            length = prefix_sum[i+1] - K
            if length > max_length:
                max_length = length
    return max_length if max_length != 0 else 0

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    print(longest_subarray(N, K, A))

if __name__ == "__main__":
    main()