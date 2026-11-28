def longest_bitonic(arr):
    n = len(arr)
    if n == 0:
        return 0

    if n == 1:
        return 1

    if n == 2:
        if arr[0] == arr[1]:
            return 1
        else:
            return 2

    lis = [1] * n
    lds = [1] * n
    max_len = 1

    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    for i in range(n - 1, -1, -1):
        for j in range(n - 1, i, -1):
            if arr[i] > arr[j] and lds[i] < lds[j] + 1:
                lds[i] = lds[j] + 1

    for i in range(n):
        max_len = max(max_len, lis[i] + lds[i] - 1)

    return max_len
This code first initializes the longest increasing subsequence (lis) and longest decreasing subsequence (lds) arrays. Then it fills up these arrays using dynamic programming. The time complexity of this solution is O(n^2), where n is the length of the input array. The space complexity is O(n).