# problem title : Move Last Node to Front
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = tokens[1:1+n]
        if n > 1:
            res = [vals[-1]] + vals[:-1]
            print(*res)
        else:
            print(*vals)
if __name__ == '__main__':
    main()
