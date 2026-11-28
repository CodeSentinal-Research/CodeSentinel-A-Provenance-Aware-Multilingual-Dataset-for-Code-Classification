def subarray_sum(N, S, arr):
    curr_sum = arr[0]
    start = 0
    for i in range(1, N):
        while curr_sum < S and i < N:
            curr_sum += arr[i]
            i += 1
        if curr_sum == S:
            return (start+1, i)
        curr_sum -= arr[i-1]
    return -1

N = int(input())
S = int(input())
arr = list(map(int, input().split()))
result = subarray_sum(N, S, arr)
print(result)