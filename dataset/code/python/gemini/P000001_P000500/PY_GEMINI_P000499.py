import sys
def main():
    s = sys.stdin.read().strip()
    # Monotonic stack to track visible elements
    stack = []
    for c in s:
        if stack and abs(ord(stack[-1]) - ord(c)) == 32:
            stack.pop()
        else:
            stack.append(c)
    print("".join(stack))
if __name__ == '__main__':
    main()