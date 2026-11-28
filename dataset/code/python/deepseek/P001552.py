Here is the Python code for the problem:

def smallest_subarray(N, X, A):
    min_length = float('inf')
    current_sum = 0
    left = 0
    right = 0
    while right < N:
        current_sum += A[right]

        while current_sum > X and left <= right:
            min_length = min(min_length, right - left + 1)
            current_sum -= A[left]
            left += 1

        right += 1

    if min_length == float('inf'):
        return -1
    else:
        return min_length


def main():
    N, X = map(int, input().split())
    A = list(map(int, input().split()))
    print(smallest_subarray(N, X, A))


if __name__ == "__main__":
    main()

This code uses a sliding window approach to solve the problem. It maintains two pointers, `left` and `right`, and a variable `min_length` to keep track of the minimum length of the subarray. The `right` pointer iterates over the array while the `left` pointer is at the start of the array. When the `right` pointer finds a valid subarray (i.e., the sum of the subarray is greater than X), it updates the `min_length` if necessary. If no valid subarray is found, it returns -1.