# problem title : Rotate Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n]) % n
        if k != 0:
            vals = vals[-k:] + vals[:-k]
        print(*vals)
if __name__ == '__main__':
    main()
