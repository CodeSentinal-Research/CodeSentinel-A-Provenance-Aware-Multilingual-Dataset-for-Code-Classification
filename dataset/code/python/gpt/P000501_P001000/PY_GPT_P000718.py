# problem title : Generate N-bit Gray Code
# Solve the stated task using standard input and standard output.
import sys
def gray_code(n):
    if n == 0: return ["0"]
    if n == 1: return ["0", "1"]
    prev = gray_code(n - 1)
    return ["0" + s for s in prev] + ["1" + s for s in reversed(prev)]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        for code in gray_code(n):
            print(code)
if __name__ == '__main__':
    main()
