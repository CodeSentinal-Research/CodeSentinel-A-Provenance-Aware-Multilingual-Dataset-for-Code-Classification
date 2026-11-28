import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        num = tokens[0]
        k = int(tokens[1])
        # Monotonic stack to track visible elements
        stack = []
        for digit in num:
            while k > 0 and stack and stack[-1] > digit:
                stack.pop()
                k -= 1
            stack.append(digit)
        if k > 0:
            stack = stack[:-k]
        res = "".join(stack).lstrip('0')
        print(res if res else "0")
if __name__ == '__main__':
    main()