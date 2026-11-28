# problem title : Shortest Subarray with Sum at Least K
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        prefix = [0] * (n + 1)
        for i in range(n): prefix[i + 1] = prefix[i] + nums[i]
        q = deque()
        min_len = n + 1
        for i in range(n + 1):
            while q and prefix[i] - prefix[q[0]] >= k:
                min_len = min(min_len, i - q.popleft())
            while q and prefix[q[-1]] >= prefix[i]:
                q.pop()
            q.append(i)
        print(min_len if min_len <= n else -1)
if __name__ == '__main__':
    main()
