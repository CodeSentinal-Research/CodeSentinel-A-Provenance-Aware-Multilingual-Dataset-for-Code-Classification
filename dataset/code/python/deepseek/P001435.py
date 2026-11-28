def count_common_words(N, M):
    first_array = [input() for _ in range(N)]
    second_array = [input() for _ in range(M)]

    first_set = set(first_array)

    count = 0

    for word in second_array:
        if word in first_set:
            count += 1

    print(count)

if __name__ == "__main__":
    N, M = map(int, input().split())
    count_common_words(N, M)