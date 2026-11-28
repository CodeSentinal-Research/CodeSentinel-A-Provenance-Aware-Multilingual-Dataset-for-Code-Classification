# problem title : Reverse a String Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def rev_str(s):
    if len(s) <= 1: return s
    return s[-1] + rev_str(s[:-1])
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        print(rev_str(tokens[0]))
if __name__ == '__main__':
    main()
