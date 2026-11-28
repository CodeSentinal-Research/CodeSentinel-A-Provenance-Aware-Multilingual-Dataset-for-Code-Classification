# problem title : Final Prices With a Special Discount in a Shop
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        prices = list(map(int, tokens[1:1+n]))
        ans = list(prices)
        stack = []
        for i, p in enumerate(prices):
            while stack and prices[stack[-1]] >= p:
                prev = stack.pop()
                ans[prev] -= p
            stack.append(i)
        print(*ans)
if __name__ == '__main__':
    main()
