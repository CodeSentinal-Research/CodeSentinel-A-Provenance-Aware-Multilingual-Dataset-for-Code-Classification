Here is a Python solution for the problem:

def min_positive_sum_subarray(N, arr):
    min_sum = float('inf')
    cur_sum = 0
    start = 0
    for i in range(N):
        cur_sum += arr[i]
        if cur_sum < 0:
            cur_sum = 0
        elif cur_sum < min_sum:
            min_sum = cur_sum
        if arr[i] == 0:
            cur_sum = 0
    if min_sum == float('inf'):
        return 0
    else:
        return min_sum

In this code, we use a sliding window technique to find the minimum positive sum subarray. We maintain a running sum of the subarray and update it whenever we encounter a negative number. If the current sum is less than zero, we reset it to zero. If the current sum is less than the minimum sum found so far, we update the minimum sum. If we encounter zero, we reset the current sum. At the end, we return the minimum sum found, or 0 if no positive sum subarray is found.