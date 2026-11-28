# problem title : Count Unique Binary Search Trees
# Solve the stated task using standard input and standard output.
import sys
def num_trees(n):
    c = 1
    for i in range(n):
        c = c * 2 * (2 * i + 1) // (i + 2)
    return c
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(num_trees(n))
if __name__ == '__main__':
    main()
