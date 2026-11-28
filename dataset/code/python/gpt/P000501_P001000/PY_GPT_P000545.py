# problem title : Constrained Subsequence Sum
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        dp = [0] * n
        q = deque()
        for i in range(n):
            while q and q[0] < i - k: q.popleft()
            dp[i] = nums[i] + (dp[q[0]] if q and dp[q[0]] > 0 else 0)
            while q and dp[q[-1]] <= dp[i]: q.pop()
            q.append(i)
        print(max(dp))
if __name__ == '__main__':
    main()
