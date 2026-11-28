Here is the Python code for the problem:

def maxSumSubmatrix(matrix, k):
    def binary_search(nums, target):
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right + 1) // 2
            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid
        return left if nums[left] <= target else -1

    n, m = len(matrix), len(matrix[0])
    res, dp = -float('inf'), [0] * (n + 1)
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[j] += matrix[i - 1][j - 1]
            for x in range(i):
                dp[j] += dp[j - i + x + 1]
            res = max(res, dp[j])
    if res <= k:
        return res
    max_sum = sum(matrix[i][j] for i in range(n) for j in range(m))
    for l in range(1, n + 1):
        for i in range(l, n + 1):
            for j in range(1, m + 1):
                for x in range(j):
                    if dp[j] - dp[j - x] + matrix[i - l][x] <= k:
                        max_sum = max(max_sum, dp[j] - dp[j - x] + matrix[i - l][x])
    return max_sum

def main():
    N, M, K = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(N)]
    print(maxSumSubmatrix(matrix, K))

if __name__ == '__main__':
    main()

In this code, we first define a helper function `binary_search` to perform a binary search on the sorted list `nums`. Then, in the main function, we first process the input matrix and calculate the prefix sum of the submatrix. After that, we use two nested loops to find the maximum sum of any rectangular submatrix that does not exceed `K`. Finally, we return the maximum sum.

Please note, this solution is based on the prefix sum and the binary search concept.