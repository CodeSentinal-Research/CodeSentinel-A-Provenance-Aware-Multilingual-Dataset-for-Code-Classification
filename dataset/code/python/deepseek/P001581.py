def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))

    max_len = 0
    count = 0
    left = 0

    for right in range(N):
        if arr[right] < 0:
            count += 1

        while count > K:
            if arr[left] < 0:
                count -= 1
            left += 1

        max_len = max(max_len, right - left + 1)

    print(max_len)


if __name__ == "__main__":
    main()