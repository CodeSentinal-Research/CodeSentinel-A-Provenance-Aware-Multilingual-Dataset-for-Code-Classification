def sliding_window_max():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))

    window = deque(arr[:K])
    max_window = max(window)

    for i in range(K, N):
        window.popleft()
        window.append(arr[i])
        max_window = max(max_window, max(window))

    print(max_window)

sliding_window_max()