Here is the Python code for the problem:

def range_sum_query(N, A, Q, L, R):
    prefix_sum = [0] * (N + 1)
    
    for i in range(1, N + 1):
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1]
    
    for _ in range(Q):
        l, r = map(int, input().split())
        print(prefix_sum[r] - prefix_sum[l - 1])


if __name__ == "__main__":
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    Q = int(input().strip())
    L, R = map(int, input().split())
    range_sum_query(N, A, Q, L, R)

In the above code, we first initialize a prefix sum array and calculate the prefix sum of the array. Then, for each query, we calculate the sum of elements from index L to R (inclusive).