import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        heights = list(map(int, tokens[1:1+n]))
        ans = [0] * n
        # Monotonic stack to track visible elements
        stack = []
        # Process from right to left
        for i in range(n - 1, -1, -1):
            h = heights[i]
            count = 0
            # Pop smaller elements that are blocked from view
            while stack and stack[-1] < h:
                stack.pop()
                count += 1
            # Can also see the next taller person
            if stack:
                count += 1
            ans[i] = count
            stack.append(h)
        print(*ans)
if __name__ == '__main__':
    main()