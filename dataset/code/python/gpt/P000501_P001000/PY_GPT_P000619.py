# problem title : Delete Middle Node of a Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        mid = n // 2
        vals.pop(mid)
        print(*vals)
if __name__ == '__main__':
    main()
