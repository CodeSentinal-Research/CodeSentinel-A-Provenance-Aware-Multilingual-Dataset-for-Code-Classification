Sure, here is the Python code for the problem:

def maxScore(nums, k):
    n = len(nums)
    dp = [0] * n
    dp[0] = nums[0]
    queue = [0]
    for i in range(1, n):
        while queue[0] < i - k:
            queue.popleft()
        dp[i] = nums[i] + dp[queue[0]]
        while queue and dp[queue[-1]] >= dp[i]:
            queue.pop()
        queue.append(i)
    return dp[-1]


def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(maxScore(nums, k))


if __name__ == '__main__':
    main()

In this code, we use a deque to store the indexes of the maximum elements we can reach. We start from the first element and keep adding the current element and the maximum element from the queue until we reach the last element. The maximum score is stored in the last element of dp.