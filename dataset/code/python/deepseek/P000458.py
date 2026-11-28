Here is the Python code:

def split_array_largest_sum():
    N, M = map(int, input().split())
    arr = list(map(int, input().split()))

    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i + 1] = prefix_sum[i] + arr[i]

    def check(mid):
        cnt = 1
        cur = prefix_sum[1]
        for i in range(2, N + 1):
            if prefix_sum[i] - prefix_sum[i - 1] - cur >= mid:
                cur = prefix_sum[i] - mid
                cnt += 1
        return cnt

    l, r = max(arr), prefix_sum[-1]
    while l < r:
        mid = (l + r) // 2
        if check(mid) <= M:
            r = mid
        else:
            l = mid + 1
    return l

print(split_array_largest_sum())

This Python program uses a binary search approach to find the minimum possible sum. The `check` function calculates the number of subarrays with a sum greater than or equal to `mid`. If this number is less than or equal to `M`, then the sum `mid` is too small, so we increase `l` to be larger. If this number is more than `M`, then the sum `mid` is too big, so we decrease `r` to be smaller. The `l` and `r` pointers in the binary search will converge to the minimum sum.