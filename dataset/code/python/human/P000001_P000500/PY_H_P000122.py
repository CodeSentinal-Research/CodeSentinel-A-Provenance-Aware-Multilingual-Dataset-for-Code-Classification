import math
import random

'''
Problem: L is an array of integers. K is an integer (1 <= K <= len(L)).
Find a subarray of L such that 
    1) the length of the subarray is equal to or larger than K, and 
    2) the sum of the elements in the subarray is maximized.

For example, if L is [2, -1, -1, -1, 4, -1, 3, 1] and K=3, the subarray
[4, -1, 3, 1] maximizes the sum and the sum is 7.

Input: L and K
Output: The maximum sum
subarray: consistent in idx
'''


# O(N^3) algorithm
def solve_n3(L, K):
    N = len(L)
    max_sum = -math.inf
    for k in range(K, N + 1):  # length
        for i in range(0, N - k + 1):  # start
            sum = 0
            for j in range(i, i + k):  # from start to start+length
                sum += L[j]
            max_sum = max(max_sum, sum)
    return max_sum


# O(N^2) algorithm
'''
initial thought: dp, 
var1: subarr length(k, len -1)
var2: start idx(0, len - subarr length + 1)
'''


def solve_n2(L, K):
    '''
    time: O(n^2)
    space: O(n^2)
    '''
    N = len(L)
    dp = [[None]*(N-K+1) for _ in range(0, N-K+1)]
    # first row
    dp[0][0] = sum(L[0:K])
    max_sum = dp[0][0]
    for i in range(1, N-K+1):
        dp[0][i] = dp[0][i-1]+L[K+i-1]
        max_sum = max(dp[0][i], max_sum)

    for i in range(1, N-K+1):  # start: N-K most
        for j in range(0, N-K-i+1):  # offset to plus K:
            # start = i
            # subarr_len = K+j
            dp[i][j] = dp[i-1][j+1]-L[i-1]
            max_sum = max(dp[i][j], max_sum)
    # [print(l) for l in dp]
    return max_sum


# O(N) algorithm
# greedy not work
# sliding window + kadane
def solve_n(L, K):
    N = len(L)

    return kadaneII(L, K)


def kadaneI(L, K):
    # O(K*N) for poping all left value when reset
    N = len(L)

    current_sum = sum(L[:K])
    current_len = K
    overall_max = current_sum

    for i in range(K, N):
        # extend current
        current_sum += L[i]
        current_len += 1
        overall_max = max(overall_max, current_sum)
        # restart a new subarr, L[i-K+1:i+1]
        new_sum = current_sum
        for j in range(i-current_len+1, i-K+1):
            new_sum -= L[j]
        if new_sum > current_sum:
            overall_max = max(overall_max, new_sum)
            current_len = K
            current_sum = new_sum

    return overall_max


def kadaneII(L, K):
    # O(N)
    N = len(L)

    current_sum = sum(L[:K])
    overall_max = current_sum
    minimum_len_sum = current_sum

    for i in range(K, N):
        # extend current
        current_sum += L[i]
        # restart a new subarr with K size (L[i-K+1:i+1]) with one
        minimum_len_sum = minimum_len_sum-L[i-K]+L[i]
        current_sum = max(current_sum, minimum_len_sum)
        overall_max = max(overall_max, current_sum)

    return overall_max

# For a given L and K, run the three algorithms (O(N^3), O(N^2) and O(N))
# and check that all the answers are equal.


def check_answers(L, K):
    answer_n3 = solve_n3(L, K)
    answer_n2 = solve_n2(L, K)
    answer_n = solve_n(L, K)
    if answer_n3 != answer_n2:
        print(L, K)
        print("Correct answer is %d but the O(N^2) algorithm answered %d" % (
            answer_n3, answer_n2))
        exit(0)
    if answer_n3 != answer_n:
        print(L, K)
        print("Correct answer is %d but the O(N) algorithm answered %d" % (
            answer_n3, answer_n))
        exit(0)


# Run tests.
def run_tests():
    # Add your test cases here.
    check_answers([1, -1, -1, -1, 3, 2], 1)
    check_answers([1, -1, -1, -1, 3, 2], 2)
    check_answers([1, -1, -1, -1, 3, 2], 3)
    check_answers([1, -1, -1, -1, 3, 2], 4)

    # Generate many test cases and run.
    for iteration in range(1000):
        length = random.randint(1, 30)
        L = [random.randint(-10, 10) for i in range(length)]
        for K in range(1, length + 1):
            check_answers(L, K)
    print("All tests pass!")


if __name__ == "__main__":
    run_tests()
