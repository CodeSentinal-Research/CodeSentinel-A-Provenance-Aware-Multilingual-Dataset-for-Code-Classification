# problem title : Remove Stars From a String
# Solve the stated task using standard input and standard output.
import sys
def main():
    s = sys.stdin.read().strip()
    stack = []
    for c in s:
        if c == '*':
            if stack: stack.pop()
        else:
            stack.append(c)
    print("".join(stack))
if __name__ == '__main__':
    main()
