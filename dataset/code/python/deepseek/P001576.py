Here is the Python code:

def count_zero_in_windows(arr, K):
    count = 0

    for i in range(len(arr)):
        if arr[i] == 0:
            count += 1
        if i >= K - 1:
            if arr[i-K+1] == 0:
                count += 1
    return count


def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_zero_in_windows(arr, K))


if __name__ == "__main__":
    main()

In this code, we first initialize a count variable to 0. We then traverse through the given array. If we find a zero, we increment the count. If the current window size has been reached (i.e., if we have traversed the array up to index K-1), we check if the previous window contains a zero. If it does, we increment the count.

In the main function, we read the values of N and K, and then the array of integers. We then print the count of zeroes in the windows of size K.