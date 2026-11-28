# problem title : Score of Parentheses
# Solve the stated task using standard input and standard output.
import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        stack = [0]
        for c in s:
            if c == '(':
                stack.append(0)
            else:
                v = stack.pop()
                stack[-1] += max(2 * v, 1)
        print(stack[0])
if __name__ == '__main__':
    main()
