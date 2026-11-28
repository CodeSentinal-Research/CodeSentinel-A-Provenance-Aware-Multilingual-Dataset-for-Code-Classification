import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        # Monotonic stack to track visible elements
        stack = []
        for v in vals:
            # Pop smaller elements that are blocked from view
            while stack and stack[-1] < v:
                stack.pop()
            stack.append(v)
        print(*stack)
if __name__ == '__main__':
    main()