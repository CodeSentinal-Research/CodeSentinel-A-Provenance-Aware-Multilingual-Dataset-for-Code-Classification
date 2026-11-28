def count_subarrays(N, K, arr):
    count = 0
    product = 1

    left = 0
    right = 0

    while right < N:
        product *= arr[right]

        while product >= K:
            product /= arr[left]
            left += 1

        count += right - left + 1

        right += 1

    return count

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_subarrays(N, K, arr))

if __name__ == "__main__":
    main()