import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        expr = tokens[1:1+n]
        # Monotonic stack to track visible elements
        stack = []
        for token in expr:
            if token in ("+", "-", "*", "/"):
                b = stack.pop()
                a = stack.pop()
                if token == '+': stack.append(a + b)
                elif token == '-': stack.append(a - b)
                elif token == '*': stack.append(a * b)
                elif token == '/': stack.append(int(a / b))
            else:
                stack.append(int(token))
        print(stack[0])
if __name__ == '__main__':
    main()