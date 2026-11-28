import sys
def main():
    s = sys.stdin.read().strip()
    # Monotonic stack to track visible elements
    stack = []
    for c in s:
        if c == '*':
            # Can also see the next taller person
            if stack: stack.pop()
        else:
            stack.append(c)
    print("".join(stack))
if __name__ == '__main__':
    main()