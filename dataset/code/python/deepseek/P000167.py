def longest_increasing_subarray():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    longest = 0
    current = 1

    for i in range(1, N):
        if A[i] > A[i-1]:
            current += 1
        else:
            longest = max(longest, current)
            current = 1

    longest = max(longest, current)
    print(longest)


if __name__ == "__main__":
    longest_increasing_subarray()