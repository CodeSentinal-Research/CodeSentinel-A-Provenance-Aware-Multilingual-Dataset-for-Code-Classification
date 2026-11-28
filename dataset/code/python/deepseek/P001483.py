def maxOnes(N, K, arr):
    left, right = 0, 0

    max_ones = 0
    max_length = 0

    zero_count = 0

    while right < N:
        if arr[right] == 0:
            zero_count += 1

        right += 1

        while zero_count > K:
            if arr[left] == 0:
                zero_count -= 1
            left += 1

        max_length = max(max_length, right - left)

    return max_length

def main():
    N, K = map(int, input().split())

    arr = list(map(int, input().split()))

    print(maxOnes(N, K, arr))

if __name__ == "__main__":
    main()