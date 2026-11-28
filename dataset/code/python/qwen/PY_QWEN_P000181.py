n, l, m = map(int, input().split())
arr = list(map(int, input().split()))
def max_sum(L, M):
    max_L = sum(arr[:L])
    curr_L = max_L
    max_M = sum(arr[L:L+M])
    curr_M = max_M
    res = max_L + max_M
    for i in range(L + M, n):
        curr_L += arr[i - M] - arr[i - M - L]
        max_L = max(max_L, curr_L)
        curr_M += arr[i] - arr[i - M]
        res = max(res, max_L + curr_M)
    return res
print(max(max_sum(l, m), max_sum(m, l)))
