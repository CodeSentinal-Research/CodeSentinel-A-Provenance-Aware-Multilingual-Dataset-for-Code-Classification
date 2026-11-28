import sys
def main():
    s = sys.stdin.read().strip()
    # Monotonic stack to track visible elements
    stack = []
    for c in s:
        if stack and stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
    print("".join(stack))
if __name__ == '__main__':
    main()