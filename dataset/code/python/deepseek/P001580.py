def longest_subarray(N, K, arr):
    odd_end = []
    even_start = []
    odd_count = 0
    even_count = 0

    for i in range(N):
        if arr[i] % 2 != 0:
            odd_count += 1
            odd_end.append(i)
        else:
            even_start.append(i)

    longest_len = 0

    for i in range(len(odd_end)):
        current_len = odd_count

        for j in range(i, len(odd_end)):
            current_len += 1
            if odd_end[j] - odd_end[i] > K:
                break
            if arr[odd_end[j]] % 2 == 0:
                current_len -= 1
                break

        for j in range(len(even_start)):
            current_len += 1
            if even_start[j] - odd_end[i] > K:
                break
            if arr[even_start[j]] % 2 == 0:
                current_len -= 1
                break

        longest_len = max(longest_len, current_len)

    return longest_len

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(longest_subarray(N, K, arr))

if __name__ == "__main__":
    main()