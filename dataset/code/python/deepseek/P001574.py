def max_in_first_window():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))

    max_deque = [max(nums[:K])]

    for i in range(K, N):
        max_deque.popleft()
        max_deque.append(max(nums[i], max_deque[-1]))

    print(max_deque[-1])


max_in_first_window()