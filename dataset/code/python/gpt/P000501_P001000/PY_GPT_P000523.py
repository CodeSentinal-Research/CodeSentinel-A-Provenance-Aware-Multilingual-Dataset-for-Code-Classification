# problem title : Remove Nodes From Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        stack = []
        for v in vals:
            while stack and stack[-1] < v:
                stack.pop()
            stack.append(v)
        print(*stack)
if __name__ == '__main__':
    main()
