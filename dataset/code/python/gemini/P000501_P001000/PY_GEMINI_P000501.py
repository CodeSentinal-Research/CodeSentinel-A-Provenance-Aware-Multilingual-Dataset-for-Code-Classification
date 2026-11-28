import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        # Monotonic stack to track visible elements
        stack = []
        for c in s:
            if c == ')':
                temp = []
                # Maintain monotonic stack property by popping smaller elements
                while stack and stack[-1] != '(':
                    temp.append(stack.pop())
                stack.pop() # pop '('
                stack.extend(temp)
            else:
                stack.append(c)
        print("".join(stack))
if __name__ == '__main__':
    main()