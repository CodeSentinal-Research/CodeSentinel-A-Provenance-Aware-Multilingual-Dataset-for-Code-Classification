Here is the Python code:

def min_operations():
    N, X = map(int, input().split())
    A = list(map(int, input().split()))

    def solve(A, X):
        if sum(A) < X:
            return -1
        elif sum(A) == X:
            return 0

        left, right = 0, len(A) - 1
        left_sum = A[left]
        right_sum = A[right]

        operations = 0

        while left < right:
            if left_sum < right_sum:
                left_sum += A[left]
                left += 1
                operations += 1
            elif right_sum < left_sum:
                right_sum += A[right]
                right -= 1
                operations += 1
            else:
                left += 1
                right -= 1
                operations += 2

            if left_sum == right_sum == X:
                return operations

        return -1

    print(solve(A, X))

min_operations()

This code first reads the number of elements N and X from the input, and then the elements themselves. It then calls the `solve` function, which calculates the minimum operations to reduce the sum to X from the beginning or end of the array. The function loops through the array, adding the elements from the ends to their sums, and incrementing the operations count each time. If the sum becomes equal to X, it returns the number of operations. If no solution is possible, it returns -1.