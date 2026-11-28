# problem title : Jump Game VI
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
        dp[0] = nums[0]
        q = deque([0])
        for i in range(1, n):
            while q and q[0] < i - k: q.popleft()
            dp[i] = nums[i] + dp[q[0]]
            while q and dp[q[-1]] <= dp[i]: q.pop()
            q.append(i)
        print(dp[-1])
if __name__ == '__main__':
    main()
