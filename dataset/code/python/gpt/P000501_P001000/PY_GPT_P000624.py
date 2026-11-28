# problem title : Segregate Even and Odd Nodes in Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        even = [x for x in vals if x % 2 == 0]
        odd = [x for x in vals if x % 2 != 0]
        print(*(even + odd))
if __name__ == '__main__':
    main()
