import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        q = deque()
        ans = []
        for i, x in enumerate(nums):
            while q and q[0] < i - k + 1: q.popleft()
            while q and nums[q[-1]] <= x: q.pop()
            q.append(i)
            if i >= k - 1: ans.append(nums[q[0]])
        print(*ans)
if __name__ == '__main__':
    main()