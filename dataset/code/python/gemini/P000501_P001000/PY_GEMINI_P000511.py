import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        ans = [-1] * n
        # Monotonic stack to track visible elements
        stack = []
        for i in range(2 * n):
            val = nums[i % n]
            while stack and nums[stack[-1]] < val:
                prev = stack.pop()
                ans[prev] = val
            if i < n:
                stack.append(i)
        print(*ans)
if __name__ == '__main__':
    main()