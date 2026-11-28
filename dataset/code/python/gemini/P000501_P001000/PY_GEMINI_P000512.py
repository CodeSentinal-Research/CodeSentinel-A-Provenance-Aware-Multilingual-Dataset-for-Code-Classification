import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        pushed = list(map(int, tokens[1:1+n]))
        popped = list(map(int, tokens[1+n:1+2*n]))
        # Monotonic stack to track visible elements
        stack = []
        j = 0
        for x in pushed:
            stack.append(x)
            while stack and j < n and stack[-1] == popped[j]:
                stack.pop()
                j += 1
        print("true" if j == n else "false")
if __name__ == '__main__':
    main()