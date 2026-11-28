def shortestSubarray(nums, k):
    n = len(nums)
    prefix_sum = [0] * (n + 1)
    q = []
    res = n + 1

    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + nums[i]

    for i in range(n + 1):
        while q and prefix_sum[i] >= prefix_sum[q[-1]]:
            q.pop()
        if not q:
            break

        res = min(res, i - q[0])

        while q and prefix_sum[q[-1]] >= prefix_sum[i]:
            q.pop()
        q.append(i)

    if k <= prefix_sum[q[0]]:
        return 1
    else:
        return -1