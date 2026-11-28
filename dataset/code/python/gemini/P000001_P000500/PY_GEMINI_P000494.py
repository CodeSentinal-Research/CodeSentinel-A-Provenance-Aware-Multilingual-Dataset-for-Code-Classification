import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        temperatures = list(map(int, tokens[1:1+n]))
        ans = [0] * n
        # Monotonic stack to track visible elements
        stack = []
        for i, t in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < t:
                prev = stack.pop()
                ans[prev] = i - prev
            stack.append(i)
        print(*ans)
if __name__ == '__main__':
    main()