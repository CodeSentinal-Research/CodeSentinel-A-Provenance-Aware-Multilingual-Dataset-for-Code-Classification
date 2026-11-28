def count_alternating_subarrays():
    N = int(input())
    binary_array = list(map(int, input().split()))

    count = 0
    alternating = None

    for i in range(N):
        if alternating is None:
            alternating = binary_array[i]
        elif binary_array[i] != alternating:
            count += 1
            alternating = binary_array[i]

    print(count)


if __name__ == "__main__":
    count_alternating_subarrays()