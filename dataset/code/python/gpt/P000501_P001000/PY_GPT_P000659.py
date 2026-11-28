# problem title : Print Linked List in Reverse Order
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = tokens[1:1+n]
        print(*(vals[::-1]))
if __name__ == '__main__':
    main()
