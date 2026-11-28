def longest_subarray(N, Limit, arr):
    prefix_max = [0]*(N+1)
    prefix_min = [0]*(N+1)
    max_diff = 0

    prefix_max[0] = arr[0]
    prefix_min[0] = arr[0]

    for i in range(1, N+1):
        prefix_max[i] = max(prefix_max[i-1], arr[i])
        prefix_min[i] = min(prefix_min[i-1], arr[i])

    for i in range(N):
        for j in range(i, N):
            if abs(prefix_max[i] - prefix_min[j]) <= Limit and j-i > max_diff:
                max_diff = j-i

    return max_diff if max_diff !=0 else -1

def main():
    N, Limit = map(int, input().split())
    arr = list(map(int, input().split()))
    print(longest_subarray(N, Limit, arr))

if __name__ == "__main__":
    main()