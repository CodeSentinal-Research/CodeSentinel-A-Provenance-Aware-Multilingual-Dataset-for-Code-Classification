def longest_subarray(N, K, arr):
    max_length = 0
    sum_map = {0: -1}  

    for i in range(N):
        K += arr[i]

        if K in sum_map:
            max_length = max(max_length, i - sum_map[K])
        else:
            sum_map[K] = i

    return max_length

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(longest_subarray(N, K, arr))

if __name__ == "__main__":
    main()