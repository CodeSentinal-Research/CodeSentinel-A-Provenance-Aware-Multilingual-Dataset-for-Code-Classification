# problem title : Reverse Substrings Between Parentheses
# Solve the stated task using standard input and standard output.
import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        stack = []
        for c in s:
            if c == ')':
                temp = []
                while stack and stack[-1] != '(':
                    temp.append(stack.pop())
                stack.pop() # pop '('
                stack.extend(temp)
            else:
                stack.append(c)
        print("".join(stack))
if __name__ == '__main__':
    main()
