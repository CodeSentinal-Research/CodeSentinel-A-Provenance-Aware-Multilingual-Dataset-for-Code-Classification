import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        prices = list(map(int, tokens[1:1+q]))
        # Monotonic stack to track visible elements
        stack = []
        for price in prices:
            span = 1
            # Maintain monotonic stack property by popping smaller elements
            while stack and stack[-1][0] <= price:
                span += stack.pop()[1]
            stack.append((price, span))
            print(span)
if __name__ == '__main__':
    main()