# problem title : Split Circular Linked List into Two Halves
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0]) if tokens[0].isdigit() and len(tokens) - 1 == int(tokens[0]) else len(tokens)
        vals = tokens[1:1+n] if n != len(tokens) else tokens
        mid = (len(vals) + 1) // 2
        h1 = vals[:mid]
        h2 = vals[mid:]
        print(" ".join(h1))
        print(" ".join(h2))
if __name__ == '__main__':
    main()
