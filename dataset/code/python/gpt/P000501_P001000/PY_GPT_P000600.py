# problem title : Odd Even Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        odd = [vals[i] for i in range(0, n, 2)]
        even = [vals[i] for i in range(1, n, 2)]
        print(*(odd + even))
if __name__ == '__main__':
    main()
