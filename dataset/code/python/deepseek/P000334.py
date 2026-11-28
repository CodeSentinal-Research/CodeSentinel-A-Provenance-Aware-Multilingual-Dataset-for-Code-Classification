Here's a Python solution for the problem using dynamic programming. 

def shortestWayToFormTarget(source: str, target: str) -> int:
    source_set = set(source)
    if not source_set.issubset(target):
        return -1

    source_order = [ord(c) for c in source]
    target_order = [ord(c) for c in target]

    source_len, target_len = len(source), len(target)
    dp = [[0] * (target_len + 1) for _ in range(source_len + 1)]

    for s in range(source_len + 1):
        dp[s][0] = s

    for t in range(1, target_len + 1):
        dp[0][t] = float('inf')

    for s in range(1, source_len + 1):
        for t in range(1, target_len + 1):
            if source_order[s - 1] == target_order[t - 1]:
                dp[s][t] = dp[s - 1][t - 1]
            else:
                dp[s][t] = min(dp[s - 1][t], dp[s][t - 1] + 1)

    return dp[source_len][target_len]

In this code, we use a 2D dynamic programming table `dp` where `dp[i][j]` represents the minimum subsequences of `source` to form `target` from `source`. The base cases are `dp[0][0] = source_len` and `dp[i][0] = i` for `i in range(source_len + 1)` and `dp[0][j] = float('inf')` for `j in range(target_len + 1)`. For every other `i` and `j`, we update the minimum subsequences. If `source[i - 1]` is equal to `target[j - 1]`, we can use the subsequences from `source`, so we update `dp[i][j]` to `dp[i - 1][j - 1]`. Otherwise, we can use `source`, or use the subsequences from `target`, so we update `dp[i][j]` to `min(dp[i - 1][j], dp[i][j - 1] + 1)`.