# problem title : Search an Element in Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = set(map(int, tokens[1:1+n]))
        target = int(tokens[1+n])
        print("true" if target in vals else "false")
if __name__ == '__main__':
    main()
