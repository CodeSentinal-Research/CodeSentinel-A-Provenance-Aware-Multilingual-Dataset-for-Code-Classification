# problem title : Partition Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        x = int(tokens[1+n])
        less = [v for v in vals if v < x]
        greater = [v for v in vals if v >= x]
        print(*(less + greater))
if __name__ == '__main__':
    main()
