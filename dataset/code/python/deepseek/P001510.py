def main():
    S = input().strip()
    K = int(input().strip())

    left, right = 0, 0
    freq = {}
    max_len = 0

    while right < len(S):
        freq[S[right]] = freq.get(S[right], 0) + 1

        while right - left + 1 - freq.get(S[right], 0) > K:
            freq[S[left]] -= 1
            left += 1

        max_len = max(max_len, right - left + 1)
        right += 1

    print(max_len)


if __name__ == "__main__":
    main()