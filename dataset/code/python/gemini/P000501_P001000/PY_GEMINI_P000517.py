import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        # Monotonic stack to track visible elements
        stack = []
        for i in range(n):
            if not stack or nums[stack[-1]] > nums[i]:
                stack.append(i)
        max_w = 0
        # Process from right to left
        for j in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] <= nums[j]:
                max_w = max(max_w, j - stack.pop())
        print(max_w)
if __name__ == '__main__':
    main()