Here is the Python code for the problem:

def solve(N, nums, Q, queries):
    prefix_sum = [0] * (N+1)
    for i in range(1, N+1):
        if (nums[i-1] % nums[0]) == 0:
            prefix_sum[i] = 1
        else:
            prefix_sum[i] = 0
    for i in range(1, N+1):
        prefix_sum[i] += prefix_sum[i-1]
    for _ in range(Q):
        L, R, X = map(int, input().split())
        print(prefix_sum[R] - prefix_sum[L-1])

if __name__ == "__main__":
    N = int(input().split()[0])
    nums = list(map(int, input().split()))
    Q = int(input().split()[0])
    queries = [list(map(int, input().split())) for _ in range(Q)]
    solve(N, nums, Q, queries)

This code first calculates the prefix sum array to get the count of divisible numbers for each index. Then it iterates over the queries and prints the count of divisible numbers in the range [L, R].