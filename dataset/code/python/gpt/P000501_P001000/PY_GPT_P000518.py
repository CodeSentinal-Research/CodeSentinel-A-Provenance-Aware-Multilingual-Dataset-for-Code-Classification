# problem title : Longest Valid Parentheses
# Solve the stated task using standard input and standard output.
import sys
def main():
    s = sys.stdin.read().strip()
    stack = [-1]
    max_len = 0
    for i, c in enumerate(s):
        if c == '(':
            stack.append(i)
        else:
            stack.pop()
            if not stack:
                stack.append(i)
            else:
                max_len = max(max_len, i - stack[-1])
    print(max_len)
if __name__ == '__main__':
    main()
