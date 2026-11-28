# problem title : Check Palindrome String Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def is_pal_rec(s, l, r):
    if l >= r: return True
    if s[l] != s[r]: return False
    return is_pal_rec(s, l + 1, r - 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        print("true" if is_pal_rec(s, 0, len(s) - 1) else "false")
if __name__ == '__main__':
    main()
