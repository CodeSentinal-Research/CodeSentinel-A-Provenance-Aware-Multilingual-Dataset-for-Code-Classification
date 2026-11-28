# problem title : Compare Two Linked Lists
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        l1 = tokens[1:1+n]
        m = int(tokens[1+n])
        l2 = tokens[2+n:2+n+m]
        print("true" if l1 == l2 else "false")
if __name__ == '__main__':
    main()
