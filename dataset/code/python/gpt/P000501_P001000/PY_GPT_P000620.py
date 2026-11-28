# problem title : Convert Binary Number in a Linked List to Integer
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        bits = tokens[1:1+n]
        print(int("".join(bits), 2))
if __name__ == '__main__':
    main()
