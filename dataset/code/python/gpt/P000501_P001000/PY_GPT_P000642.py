# problem title : Insert Node at a Given Position
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        pos = int(tokens[1+n])
        val = int(tokens[2+n])
        vals.insert(pos, val)
        print(*vals)
if __name__ == '__main__':
    main()
