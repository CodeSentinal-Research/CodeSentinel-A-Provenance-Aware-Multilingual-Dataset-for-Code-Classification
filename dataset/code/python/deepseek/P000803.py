def numSubmatrixSumTarget(matrix, target):
    N, M = len(matrix), len(matrix[0])
    prefix_sum = [[0]*(M+1) for _ in range(N+1)]

    for i in range(N):
        for j in range(M):
            prefix_sum[i+1][j+1] = prefix_sum[i+1][j] + prefix_sum[i][j+1] - prefix_sum[i][j] + matrix[i][j]

    res = 0
    for c1 in range(M):
        for c2 in range(c1, M):
            sums = set()
            cur = 0
            for r in range(N):
                cur += prefix_sum[r+1][c2+1] - prefix_sum[r+1][c1]
                diff = cur - target
                if diff in sums:
                    res += sums[diff]
                sums.add(cur)
    return res