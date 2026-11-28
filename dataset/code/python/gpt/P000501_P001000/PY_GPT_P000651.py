# problem title : Delete Last Node of Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = tokens[1:1+n]
        if n > 1:
            print(*(vals[:-1]))
        elif n == 1:
            print()
if __name__ == '__main__':
    main()
