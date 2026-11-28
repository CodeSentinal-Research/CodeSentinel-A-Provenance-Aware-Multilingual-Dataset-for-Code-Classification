# problem title : Ternary Expression Parser
# Solve the stated task using standard input and standard output.
import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        stack = []
        for c in reversed(s):
            if stack and stack[-1] == '?':
                stack.pop() # '?'
                first = stack.pop()
                stack.pop() # ':'
                second = stack.pop()
                stack.append(first if c == 'T' else second)
            else:
                stack.append(c)
        print(stack[0])
if __name__ == '__main__':
    main()
