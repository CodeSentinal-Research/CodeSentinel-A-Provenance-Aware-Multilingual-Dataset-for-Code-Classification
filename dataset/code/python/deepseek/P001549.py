def countWindows(N, K, arr):
    counter = 0

    for i in range(N - K + 1):
        if all(arr[i:i + K]):
            counter += 1

    return counter


N, K = map(int, input().split())
arr = list(map(int, input().split()))

print(countWindows(N, K, arr))