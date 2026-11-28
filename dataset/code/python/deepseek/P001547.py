def max_odd_elements_in_window():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))

    count = 0
    max_count = 0

    for i in range(N):
        if arr[i] % 2 == 1:
            count += 1
        if i >= K - 1:
            if arr[i - K + 1] % 2 == 1:
                count -= 1
            if arr[i] % 2 == 1:
                max_count = max(max_count, count)

    print(max_count)

max_odd_elements_in_window()