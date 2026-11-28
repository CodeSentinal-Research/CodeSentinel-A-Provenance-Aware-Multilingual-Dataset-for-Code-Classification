# problem title : Remove Zero Sum Consecutive Nodes from Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        stack = []
        for x in vals:
            stack.append(x)
            s = 0
            for j in range(len(stack) - 1, -1, -1):
                s += stack[j]
                if s == 0:
                    stack = stack[:j]
                    break
        print(*stack)
if __name__ == '__main__':
    main()
